/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:26:54 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/02 14:32:13 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*di(t_arg *arg, int base, va_list ap)
{
	arg->base = base;
	if (arg->l)
		arg->string = ft_itoa_base(va_arg(ap, long), arg);
	else if (arg->ll)
		arg->string = ft_itoa_base(va_arg(ap, long long), arg);
	else if (arg->h)
		arg->string = ft_itoa_base((short)va_arg(ap, int), arg);
	else if (arg->hh)
		arg->string = ft_itoa_base((char)va_arg(ap, int), arg);
	else
		arg->string = ft_itoa_base(((int)va_arg(ap, int)), arg);
	return (arg->string);
}

char		*oux(t_arg *arg, int base, va_list ap)
{
	arg->base = base;
	if (arg->l)
		arg->string = ft_itoa_base(va_arg(ap, unsigned long), arg);
	else if (arg->ll || arg->type == 'p')
		arg->string = ft_itoa_base(va_arg(ap, unsigned long long), arg);
	else if (arg->h)
		arg->string = ft_itoa_base((unsigned short)va_arg(ap, unsigned int),
									arg);
	else if (arg->hh)
		arg->string = ft_itoa_base((unsigned char)va_arg(ap, unsigned int),
									arg);
	else
		arg->string = ft_itoa_base(va_arg(ap, unsigned int), arg);
	return (arg->string);
}
