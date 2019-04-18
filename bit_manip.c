/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 23:31:34 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/17 23:31:44 by bvilla           ###   ########.fr       */
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
