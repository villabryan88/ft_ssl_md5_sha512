/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 01:12:08 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/04 15:18:32 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	char				*num;
	int					neg;
	long long			place;
	int					i;
	unsigned long long	val;

	place = 1;
	neg = n < 0 ? 1 : 0;
	i = 1;
	val = (unsigned long long)(n * (neg ? -1 : 1));
	while (val / place >= 10 && i++)
		place *= 10;
	if (!(num = (char*)malloc(sizeof(char) * (i + neg + 1))))
		return (NULL);
	i = 0;
	if (neg)
		num[i++] = '-';
	while (place > 0)
	{
		num[i++] = val / place + '0';
		val %= place;
		place /= 10;
	}
	num[i] = '\0';
	return (num);
}
