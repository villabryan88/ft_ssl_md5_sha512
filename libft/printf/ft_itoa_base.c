/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:07:47 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/02 23:27:49 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*main_logic(unsigned long long val, int base, int prec, int sign)
{
	int					i;
	unsigned long long	place;
	char				*str;

	place = 1;
	i = 1;
	while (val / place >= (unsigned long long)base && i++)
		place *= base;
	prec = prec - i;
	str = (char*)malloc(sizeof(char) * ((prec > 0 ? i + prec : i) + sign + 1));
	i = 0;
	sign == 1 && (str[0] = '+') && ++i && sign--;
	while (prec-- > 0 || sign-- > 0)
		str[i++] = '0';
	while (place > 0)
	{
		str[i] = val / place + '0';
		if (str[i] > '9')
			str[i] += 39;
		val %= place;
		place /= base;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base(long long value, t_arg *arg)
{
	int					neg;
	unsigned long long	val;
	char				*ret;
	int					prec;
	int					sign;

	neg = arg->base == 10 && value < 0 ? 1 : 0;
	if (arg->base != 10)
		arg->plus = 0;
	if (arg->base == -10)
		arg->base = 10;
	val = (unsigned long long)(value * (neg ? -1 : 1));
	sign = double_sign(arg, neg);
	prec = 0;
	if (arg->prec)
		prec = arg->prec - 1;
	else if (arg->zero && arg->width && !arg->left)
		prec = arg->width - sign;
	ret = main_logic(val, arg->base, prec, sign);
	arg->space && is_di(arg->type) && !arg->plus && (ret[0] = ' ');
	if (neg)
		ret[0] = '-';
	if (sign == 2)
		ret[1] = arg->type == 'X' ? 'X' : 'x';
	return (ret);
}
