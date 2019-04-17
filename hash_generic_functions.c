/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_generic_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:00:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/16 22:16:49 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

unsigned int	ltrot(unsigned int x, unsigned int c)
{
	return ((x << c) | (x >> (32 - c)));
}

unsigned int	rtrot(unsigned int x, unsigned int c)
{
	return ((x >> c) | (x << (32 - c)));
}


unsigned int	*break_into_words(unsigned char *chunk)
{
	static unsigned int			m[16];

	ft_memcpy(m, chunk, sizeof(int) * 16);
	return (m);
}

int				get_next_chunk(char *msg, int fd, unsigned char *buf)
{
	static unsigned int	i = 0;
	static char			*curr_msg = NULL;
	unsigned int		len;


	if (fd >= 0)
		return(read(fd, buf, BUF_SIZE));
	else
	{
		if (curr_msg != msg)
		{
			i = 0;
			curr_msg = msg;
		}
		if (i >= ft_strlen(msg))
		{
			return (0);
		}
		len = ft_strlen(msg + i);
		if (len > BUF_SIZE)
			len = BUF_SIZE;
		ft_strncpy((char*)buf, msg + i, len);
		i += len;
		return (len);
	}
}

unsigned char	*eight_byte_big_endian(unsigned long long n)
{
	static unsigned char	big_end[8];
	int						i;

	i = 7;
	while (i >= 0)
	{
		big_end[i] = n % 256;
		n /= 256;
		i--;
	}
	return (big_end);
}

void		reverse_bytes(void *s, size_t n)
{
	unsigned int		i;
	unsigned char		tmp;

	i = 0;
	n--;
	while (i < n)
	{
		tmp = ((unsigned char*)s)[i];
		((unsigned char*)s)[i] = ((unsigned char*)s)[n];
		((unsigned char*)s)[n] = tmp;
	i++;
	n--;
	}
}

char	*digest_to_string(unsigned char *digest, int n)
{
	int		i;
	char	*str;
	char	*val;

	val = "0123456789abcdef";

	str = ft_memalloc(sizeof(char) * (n * 2 + 1));
	i = 0;
	while (i < n * 2)
	{
		str[i] = val[*digest / 16];
		str[i + 1] = val[*digest % 16];
		digest++;
		i += 2;
	}
	return (str);
}
