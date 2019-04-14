/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 22:03:14 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/04 15:16:12 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		flip_more_flags(char **c, t_arg *arg)
{
	if (**c == 'h')
	{
		if (*(*c + 1) == 'h' && (*c)++)
			(*arg).hh = 1;
		else
			(*arg).h = 1;
		return (1);
	}
	if (**c == 'l')
	{
		if (*(*c + 1) == 'l' && (*c)++)
			(*arg).ll = 1;
		else
			(*arg).l = 1;
		return (1);
	}
	if (**c == 'L' && ((*arg).bigl = 1))
		return (1);
	if (**c == '+' && ((*arg).plus = 1))
		return (1);
	if (!is_spec(**c))
		return (0);
	return (0);
}

int		flip_flags(char **c, t_arg *arg)
{
	if (**c == '-' && ((*arg).left = 1))
		return (1);
	if (**c == '+' && ((*arg).plus = 1))
		return (1);
	if (**c == ' ' && ((*arg).space = 1))
		return (1);
	if (**c == '#' && ((*arg).hash = 1))
		return (1);
	if (**c == '0' && ((*arg).zero = 1))
		return (1);
	if (ft_isdigit(**c) && ((*arg).width = ft_atoi(*c)))
	{
		while (ft_isdigit(*(*c + 1)))
			*c += 1;
		return (1);
	}
	if (**c == '.' && ((*arg).prec = ft_atoi(++(*c)) + 1))
	{
		while (ft_isdigit(*(*c + 1)))
			*c += 1;
		if (is_spec(**c))
			return (0);
		return (1);
	}
	return (flip_more_flags(c, arg));
}
