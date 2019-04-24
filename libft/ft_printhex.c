/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:32:40 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/23 15:40:50 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_printhex(void *str, size_t n)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = str;
	while (i < n)
	{
		ft_printf("%.2hhx", s[i]);
		i++;
	}
	ft_printf("\n");
}
