/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:40:10 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 20:37:54 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	adj_width(t_arg *arg)
{
	unsigned int	len;
	unsigned int	width;
	char			*new;

	width = arg->width;
	len = ft_strlen(arg->string) + (arg->null ? 1 : 0);
	if (width > len)
	{
		new = (char*)malloc(sizeof(char) * (width + 1));
		new[width] = '\0';
		if (!is_dioux(arg->type) && arg->type != 'p' && arg->zero && !arg->left)
			ft_memset(new, '0', width);
		else
			ft_memset(new, ' ', width);
		if (arg->left)
			ft_memcpy(new, arg->string, len);
		else
			ft_memcpy(new + width - len, arg->string, len);
		free(arg->string);
		arg->string = new;
	}
	else
		arg->width = len;
}

void	do_hash(t_arg *arg)
{
	char	zero;
	int		i;

	i = -1;
	zero = 1;
	while (arg->string[++i])
		if (arg->string[i] != '0')
			zero = 0;
	if (!arg->hash || zero)
		return ;
	if (arg->type == 'x' || arg->type == 'X')
	{
		if (ft_strcmp(arg->string, "0x0") && ft_strcmp(arg->string, "0X0"))
			return ;
		free(arg->string);
		arg->string = ft_strdup("0");
	}
	if (arg->type == 'o')
	{
		if (arg->string[0] != '0')
			arg->string = ft_strjoin_free("0", arg->string, 0, 1);
	}
}

void	float_width_hash(t_arg *arg, int neg)
{
	int		len;
	char	*new;

	len = ft_strlen(arg->string);
	if (!arg->hash && arg->string[len - 1] == '.')
		arg->string[--len] = '\0';
	len = arg->width - len - (neg || arg->plus || arg->space);
	if (len > 0 && arg->zero && !arg->left)
	{
		new = ft_strnew(len);
		ft_memset(new, '0', len);
		arg->string = ft_strjoin_free(new, arg->string, 1, 1);
	}
}

void	do_prec(t_arg *arg)
{
	char	*fre;

	if (!arg->prec)
		return ;
	if (arg->type == 's')
	{
		if (ft_strlen(arg->string) > (unsigned int)arg->prec - 1)
		{
			fre = arg->string;
			arg->string = ft_strsub(arg->string, 0, arg->prec - 1);
			free(fre);
		}
	}
	if (is_dioux(arg->type) && arg->prec == 1 && !ft_strcmp(arg->string, "0"))
	{
		if (arg->type == 'o' && arg->hash)
			return ;
		free(arg->string);
		arg->string = ft_strdup("");
	}
}
