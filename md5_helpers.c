/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:46:07 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/13 22:52:46 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

unsigned int	leftrotate (unsigned int x, unsigned int c)
{
return ((x << c) | (x >> (32 - c)));
}
//Words stay in same order, don't worry about making them little endian
unsigned int	*break_into_words(unsigned char *chunk)
{
static unsigned int			m[16];

ft_memcpy(m, chunk, sizeof(int) * 16);
return (m);
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

void		print_buf_hex(unsigned char *buf)
{
	int		i;

	i = 0;
	while (i < 64)
		ft_printf("%.2hhx", buf[i++]);
	ft_printf("\n");
}
