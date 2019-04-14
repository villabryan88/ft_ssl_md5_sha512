/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:36:39 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/04 14:57:18 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		count_args(char *s)
{
	int		args;

	args = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*s && !is_spec(*s))
				s++;
			if (*s == 0)
				return (-1);
			args++;
		}
		s++;
	}
	return (args);
}

int		make_string(t_arg *arg, va_list ap)
{
	char	tmp;

	if (arg->type == 'c')
	{
		tmp = va_arg(ap, int);
		if (tmp == 0)
			arg->null = 1;
		arg->string = ft_strnew(1);
		ft_memcpy(arg->string, &tmp, 1);
	}
	if (arg->type == 's')
	{
		arg->string = va_arg(ap, char*);
		if (!arg->string)
			arg->string = ft_strdup("(null)");
		else
			arg->string = ft_strdup(arg->string);
	}
	if (arg->type == 'd' || arg->type == 'i')
		di(arg, 10, ap);
	if (arg->type == 'o')
		oux(arg, 8, ap);
	if (arg->type == 'x')
		oux(arg, 16, ap);
	return (cont_make_string(arg, ap));
}

int		cont_make_string(t_arg *arg, va_list ap)
{
	if (arg->type == 'X')
	{
		oux(arg, 16, ap);
		ft_strtoupper(arg->string);
	}
	if (arg->type == 'u')
		oux(arg, -10, ap);
	if (arg->type == 'p')
		arg->string = oux(arg, 16, ap);
	if (arg->type == '%')
	{
		arg->string = (char*)ft_memalloc(sizeof(char) * 2);
		arg->string[0] = '%';
	}
	if (arg->type == 'f')
		arg->string = flt(arg, ap);
	return (0);
}

int		parse_args(char *s, t_arg *list, va_list ap)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*s && !is_spec(*(++s)))
				while (*s && flip_flags(&s, list + i))
					s++;
			if (!is_spec(*s))
				return (-1);
			list[i].type = *s;
			make_string(list + i, ap);
			do_hash(list + i);
			do_prec(list + i);
			adj_width(list + i);
			len += (list[i++].width) - 1;
		}
		len++;
		s++;
	}
	return (len);
}

int		pop_args(char *s, char *new, t_arg *list)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			ft_memcpy(new + len, list[i].string, list[i].width);
			free(list[i].string);
			len += (list[i].width) - 1;
			i++;
			s++;
			while (*s && !is_spec(*s))
				s++;
		}
		else
			new[len] = *s;
		s++;
		len++;
	}
	new[len] = '\0';
	return (len);
}
