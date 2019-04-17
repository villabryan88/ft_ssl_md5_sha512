/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:02:59 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/16 22:03:41 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#define A new_digest[0]
#define B new_digest[1]
#define C new_digest[2]
#define D new_digest[3]

unsigned int g_s[64] = {
   		7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
		5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
		4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
		6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};
static unsigned int g_k[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};
static int			get_next_parsed_chunk(char *msg, int fd, unsigned char *buf)
{
	int							red;
	static unsigned long long	len = 0;
	static int					append_started = 0;
	static int					append_finished = 0;

	red = get_next_chunk(msg, fd, buf);
	if (red == -1)
		return (ERR);
	len += red * 8;
	if (!red && append_finished)
	{
		append_started = 0;
		append_finished = 0;
		len = 0;
		return (0);
	}
	if (red < 64)
	{
		ft_bzero(buf + red, 64 - red);
		if (!append_started)
		{
			buf[red] = 128;
			append_started = 1;
		}
		if (red < 56)
		{
			*((unsigned long long *)(buf + 56)) = len;
			append_finished = 1;
		}
	}
	return (1);
}



static unsigned int	*get_new_digest(unsigned char *chunk, 
								unsigned int curr_digest[4])
{
	static unsigned int	new_digest[4];
	unsigned int		*m;
	unsigned int		i;
	unsigned int		g;
	unsigned int		f;

	m = break_into_words(chunk);	   	
	ft_memcpy(new_digest, curr_digest, sizeof(int) * 4);
	i = 0;
	while (i < 64)
	{
		if (i <= 15)
		{
			f = (B & C) | ((~B) & D);
			g = i;
		}
		else if (i <= 31)
		{
			f = (D & B) | ((~D) & C);
			g = (5 * i + 1) % 16;
		}
		else if (i <= 47)
		{
			f = B ^ C ^ D;
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = C ^ (B | (~D));
			g = (7 * i) % 16;
		}
		f = f + A + g_k[i] + m[g];
		A = D;
		D = C;
		C = B;
		B = B + ltrot(f, g_s[i]);
 	   i++;
	}
	return (new_digest);
}


int				md5(char *msg, int fd, char **digest)
{
	unsigned char		buf[BUF_SIZE];
	static unsigned int	curr_digest[4];
	unsigned int		*new_digest;
	int					i;
	int					err;

	curr_digest[0] = 0x67452301;
	curr_digest[1] = 0xefcdab89;
	curr_digest[2] = 0x98badcfe;
	curr_digest[3] = 0x10325476;

	while((err = get_next_parsed_chunk(msg, fd, buf)) > 0)
	{
	    new_digest = get_new_digest(buf, curr_digest);
		i = 0;
		while (i < 4)
		{
			curr_digest[i] += new_digest[i];
			i++;
		}
	}
	if (err == ERR)
		return (ERR);
	*digest = digest_to_string((unsigned char*)curr_digest, 16);
	return (0);
}
/*
unsigned char 		*md5(char *msg, char *file)
{
	int				fd;
	unsigned char	*digest;


	fd = file ? open(file, O_RDONLY) : -2;
	if (fd == -1)
		return(NULL);

	if (md5_get_digest(msg, fd, &digest) == ERR)
		return(NULL);

	return (digest);
}
*/
