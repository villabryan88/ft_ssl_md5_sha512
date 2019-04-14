/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 13:22:52 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/02 16:24:08 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*parse_long_double(char *neg, int *exp, unsigned long long *man,
							t_ldblfloat *b)
{
	*neg = (b->num[1] & ((1L << 16) - 1)) >> 15;
	*exp = (b->num[1] & ((1 << 15) - 1)) - 16383 - 63;
	*man = b->num[0];
	if (*exp == 32767 - 16383 - 63)
	{
		if (*man != 0 && *man != 9223372036854775808u)
			return (ft_strdup("nan"));
		return (ft_strdup("inf"));
	}
	if (*exp == -16383 - 63)
		(*exp)++;
	return (NULL);
}

char	*parse_double(char *neg, int *exp, unsigned long long *man,
							t_float *a)
{
	*neg = a->num >> 63;
	*exp = ((a->num << 1) >> 53) - 1023 - 52;
	*man = (a->num & ((1L << 52) - 1));
	if (*exp == 2047 - 1023 - 52)
	{
		if (*man)
			return (ft_strdup("nan"));
		return (ft_strdup("inf"));
	}
	if (*exp != -1075)
		*man += 1L << 52;
	else
		(*exp)++;
	return (NULL);
}

void	make_float_string(t_arg *arg, char neg, int exp, unsigned long long man)
{
	if (!arg->string)
	{
		arg->string = main_logic(man, 10, 0, 0);
		arg->string = ft_strjoin_free(arg->string, ".", 1, 0);
		while (exp > 0 && exp--)
			multiply_two(&(arg->string));
		while (exp++ < 0)
			divide_two(&(arg->string));
		format_float(arg);
		float_width_hash(arg, neg);
	}
	if (arg->string[0] != 'n')
	{
		if (arg->plus && !neg)
			arg->string = ft_strjoin_free("+", arg->string, 0, 1);
		else if (neg)
			arg->string = ft_strjoin_free("-", arg->string, 0, 1);
		else if (arg->space)
			arg->string = ft_strjoin_free(" ", arg->string, 0, 1);
	}
}

char	*flt(t_arg *arg, va_list ap)
{
	t_float				a;
	t_ldblfloat			b;
	char				neg;
	int					exp;
	unsigned long long	man;

	if (!arg->prec)
		arg->prec = 7;
	if (arg->bigl)
	{
		b.ldbl = va_arg(ap, long double);
		arg->string = parse_long_double(&neg, &exp, &man, &b);
	}
	else
	{
		a.flt = va_arg(ap, double);
		arg->string = parse_double(&neg, &exp, &man, &a);
	}
	make_float_string(arg, neg, exp, man);
	return (arg->string);
}
