/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:32:50 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/04 15:17:26 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putnstr(char const *s, size_t n)
{
	if (!s)
		return ;
	write(1, s, n);
}

int		ft_printf(char *s, ...)
{
	int		ac;
	t_arg	*arg_lst;
	int		ret;
	char	*new;
	va_list	ap;

	ac = count_args(s);
	arg_lst = (t_arg*)ft_memalloc(sizeof(t_arg) * ac);
	va_start(ap, s);
	ret = parse_args(s, arg_lst, ap);
	if (ret == -1)
	{
		ft_putstr("error: invalid format string: '");
		ft_putstr(s);
		ft_putstr("'\n");
		free(arg_lst);
		return (-1);
	}
	new = (char*)malloc(sizeof(char) * (ret + 1));
	pop_args(s, new, arg_lst);
	ft_putnstr(new, ret);
	va_end(ap);
	free(arg_lst);
	free(new);
	return (ret);
}
