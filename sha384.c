/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:14:22 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/23 19:09:22 by bvilla           ###   ########.fr       */
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

static unsigned long	g_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

static void				make_word_array(unsigned char *chunk, unsigned long *w)
{
	unsigned int	i;
	unsigned long	s[2];

	ft_memcpy(w, chunk, sizeof(long) * 16);
	i = 0;
	while (i < 16)
		reverse_bytes(w + i++, sizeof(long));
	i = 16;
	while (i < 80)
	{
		s[0] = rtrot64(w[i - 15], 1) ^ rtrot64(w[i - 15], 8) ^ (w[i - 15] >> 7);
		s[1] = rtrot64(w[i - 2], 19) ^ rtrot64(w[i - 2], 61) ^ (w[i - 2] >> 6);
		w[i] = w[i - 16] + s[0] + w[i - 7] + s[1];
		i++;
	}
}

static void				do_hashing(unsigned long *new_digest, unsigned long *w,
									unsigned long i)
{
	unsigned long		s[2];
	unsigned long		tmp[2];
	unsigned long		ch;
	unsigned long		maj;

	s[1] = rtrot64(E, 14) ^ rtrot64(E, 18) ^ rtrot64(E, 41);
	ch = (E & F) ^ ((~E) & G);
	tmp[0] = H + s[1] + ch + g_k[i] + w[i];
	s[0] = rtrot64(A, 28) ^ rtrot64(A, 34) ^ rtrot64(A, 39);
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

static unsigned long	*get_new_digest(unsigned char *chunk,
								unsigned long curr_digest[8])
{
	static unsigned long	new_digest[8];
	unsigned long			w[80];
	unsigned long			i;

	make_word_array(chunk, w);
	ft_memcpy(new_digest, curr_digest, sizeof(long) * 8);
	i = 0;
	while (i < 80)
	{
		do_hashing(new_digest, w, i);
		i++;
	}
	return (new_digest);
}

static void				set_start_values(unsigned long *curr_digest)
{
	curr_digest[0] = 0xcbbb9d5dc1059ed8;
	curr_digest[1] = 0x629a292a367cd507;
	curr_digest[2] = 0x9159015a3070dd17;
	curr_digest[3] = 0x152fecd8f70e5939;
	curr_digest[4] = 0x67332667ffc00b31;
	curr_digest[5] = 0x8eb44a8768581511;
	curr_digest[6] = 0xdb0c2e0d64f98fa7;
	curr_digest[7] = 0x47b5481dbefa4fa4;
}

int						sha384(char *msg, int fd, char **digest)
{
	unsigned char			buf[128];
	static unsigned long	curr_digest[8];
	unsigned long			*new_digest;
	int						i;
	int						err;

	set_start_values(curr_digest);
	while ((err = get_next_parsed_chunk1024(msg, fd, buf, big_end)) > 0)
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
		reverse_bytes(curr_digest + i++, sizeof(long));
	*digest = digest_to_string((unsigned char*)curr_digest, 48);
	return (0);
}
