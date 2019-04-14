/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:26:06 by bvilla            #+#    #+#             */
/*   Updated: 2018/10/28 22:24:02 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n)
		while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] && i < n - 1)
			i++;
	else
		return (0);
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
