/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:45:48 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/06 00:31:59 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisint(char *s)
{
	char	*check;
	int		ret;

	check = ft_itoa(ft_atoi(s));
	ret = !ft_strcmp(s, check);
	free(check);
	return (ret);
}
