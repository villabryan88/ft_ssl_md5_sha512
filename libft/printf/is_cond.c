/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cond.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:04:37 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/02 23:39:07 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		is_spec(char c)
{
	return (c == 'c' || c == 'd' || c == 'f' || c == 'o' || c == 's' || c == '%'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == 'i');
}

int		is_dioux(char c)
{
	return (c == 'd' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'i');
}

int		is_di(char c)
{
	return (c == 'd' || c == 'i');
}

int		double_sign(t_arg *arg, int neg)
{
	if (arg->type == 'p')
		return (2);
	if (arg->type == 'x' || arg->type == 'X')
		if (arg->hash)
			return (2);
	if (!is_di(arg->type))
		return (0);
	return (neg || arg->plus || arg->space);
}
