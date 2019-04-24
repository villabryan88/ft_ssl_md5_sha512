/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_generic_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:00:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/23 16:02:45 by bvilla           ###   ########.fr       */
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

unsigned long	rtrot64(unsigned long x, unsigned long c)
{
	return ((x >> c) | (x << (64 - c)));
}

void			reverse_bytes(void *s, size_t n)
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

char			*digest_to_string(unsigned char *digest, int n)
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
