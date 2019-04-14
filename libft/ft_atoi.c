/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:24:12 by bvilla            #+#    #+#             */
/*   Updated: 2019/02/18 23:36:43 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		neg;

	neg = 1;
	nb = 0;
	while (*str && ft_isspace((int)(*str)))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		neg = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (int)(*(str++) - '0');
	}
	return (nb * neg);
}
