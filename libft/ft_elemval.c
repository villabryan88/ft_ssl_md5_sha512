/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:42:48 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 20:38:52 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_elemval(void *arr, size_t size)
{
	long long		sum;
	long long		place;
	unsigned long	i;

	i = 0;
	place = 1;
	sum = 0;
	while (i < size)
	{
		sum += ((unsigned char*)arr)[i] * place;
		place *= 256;
		i++;
	}
	return (sum);
}
