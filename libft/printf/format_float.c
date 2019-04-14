/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:04:13 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/04 16:30:05 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*float_prec(t_arg *arg, int p, int prev, int i)
{
	char	*new;

	new = NULL;
	if (p)
		new = ft_strjoin_free(arg->string,
				ft_memset(ft_strnew(p), '0', p), 0, 1);
	if (arg->string[i])
	{
		new = ft_strsub(arg->string, 0, i);
		if (arg->string[i - 1] != '.')
			prev = arg->string[i - 1] - '0';
		if (arg->string[i] >= '5')
		{
			if (arg->string[i] == '5' && !arg->string[i + 1])
				if (prev % 2 == 0)
					return (new);
			round_up(&new);
		}
	}
	return (new);
}

void	format_float(t_arg *arg)
{
	int		prec;
	int		i;
	char	*new;
	int		prev;

	new = NULL;
	i = 0;
	prec = arg->prec - 1;
	while (arg->string[i] != '.')
		i++;
	prev = arg->string[i - 1] - '0';
	while (arg->string[++i] && prec)
		prec--;
	new = float_prec(arg, prec, prev, i);
	if (new)
	{
		free(arg->string);
		arg->string = new;
	}
}
