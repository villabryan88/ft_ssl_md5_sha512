/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:39:03 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/18 22:48:51 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#define A new_digest[0]
#define B new_digest[1]
#define C new_digest[2]
#define D new_digest[3]
#define E new_digest[4]
#define F new_digest[5]
#define G new_digest[6]
#define H new_digest[7]

static unsigned int	g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void			make_word_array(unsigned char *chunk, unsigned int *w)
{
	unsigned int	i;
	unsigned int	s[2];

	ft_memcpy(w, chunk, sizeof(int) * 16);
	i = 0;
	while (i < 16)
		reverse_bytes(w + i++, sizeof(int));
	i = 16;
	while (i < 64)
	{
		s[0] = rtrot(w[i - 15], 7) ^ rtrot(w[i - 15], 18) ^ (w[i - 15] >> 3);
		s[1] = rtrot(w[i - 2], 17) ^ rtrot(w[i - 2], 19) ^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + s[0] + w[i - 7] + s[1];
		i++;
	}
}

static void			do_hashing(unsigned int *new_digest, unsigned int *w,
							unsigned int i)
{
	unsigned int		s[2];
	unsigned int		tmp[2];
	unsigned int		ch;
	unsigned int		maj;

	s[1] = rtrot(E, 6) ^ rtrot(E, 11) ^ rtrot(E, 25);
	ch = (E & F) ^ ((~E) & G);
	tmp[0] = H + s[1] + ch + g_k[i] + w[i];
	s[0] = rtrot(A, 2) ^ rtrot(A, 13) ^ rtrot(A, 22);
	maj = (A & B) ^ (A & C) ^ (B & C);
	tmp[1] = s[0] + maj;
	H = G;
	G = F;
	F = E;
	E = D + tmp[0];
	D = C;
	C = B;
	B = A;
	A = tmp[0] + tmp[1];
}

static unsigned int	*get_new_digest(unsigned char *chunk,
								unsigned int curr_digest[8])
{
	static unsigned int	new_digest[8];
	unsigned int		w[64];
	unsigned int		i;

	make_word_array(chunk, w);
	ft_memcpy(new_digest, curr_digest, sizeof(int) * 8);
	i = 0;
	while (i < 64)
	{
		do_hashing(new_digest, w, i);
		i++;
	}
	return (new_digest);
}

static void			set_start_values(unsigned int *curr_digest)
{
	curr_digest[0] = 0xc1059ed8;
	curr_digest[1] = 0x367cd507;
	curr_digest[2] = 0x3070dd17;
	curr_digest[3] = 0xf70e5939;
	curr_digest[4] = 0xffc00b31;
	curr_digest[5] = 0x68581511;
	curr_digest[6] = 0x64f98fa7;
	curr_digest[7] = 0xbefa4fa4;
}

int					sha224(char *msg, int fd, char **digest)
{
	unsigned char		buf[BUF_SIZE];
	static unsigned int	curr_digest[8];
	unsigned int		*new_digest;
	int					i;
	int					err;

	set_start_values(curr_digest);
	while ((err = get_next_parsed_chunk(msg, fd, buf, big_end)) > 0)
	{
		new_digest = get_new_digest(buf, curr_digest);
		i = 0;
		while (i < 8)
		{
			curr_digest[i] += new_digest[i];
			i++;
		}
	}
	if (err == ERR)
		return (ERR);
	i = 0;
	while (i < 8)
		reverse_bytes(curr_digest + i++, sizeof(int));
	*digest = digest_to_string((unsigned char*)curr_digest, 28);
	return (0);
}
