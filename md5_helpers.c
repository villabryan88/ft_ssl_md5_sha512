/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:46:07 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/13 19:31:26 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

unsigned int leftrotate (x, c)
{
    return ((x << c) | (x >> (32 - c)));
}

unsigned int	*break_into_words(char *chunk)
{
	static unsigned int			m[16];

	ft_memcpy(m, chunk, sizeof(int) * 16);
	//do i have to account for endianess?
	return (m);
}

