/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:58:47 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/02 17:51:33 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	multiply_two(char **s)
{
	int		i;
	int		carryover;
	int		temp;
	char	*new;

	if (**s >= '5')
		new = ft_strjoin("0", *s);
	else
		new = ft_strdup(*s);
	i = 0;
	while (new[i])
		i++;
	i--;
	carryover = 0;
	while (--i >= 0)
	{
		temp = carryover;
		carryover = (new[i] - '0') * 2 / 10;
		new[i] = (new[i] - '0') * 2 % 10 + temp + '0';
	}
	free(*s);
	*s = new;
}

char	*format_divide_string(char *s, int *carryover)
{
	int		i;
	char	*new;

	i = 0;
	*carryover = 0;
	if (s[0] == '1' && s[1] != '.')
		*carryover = 10;
	while (s[i + 1])
		i++;
	if (s[i] == '.')
		i--;
	if ((s[i] - '0') % 2 == 1)
		new = ft_strjoin(s + (*carryover ? 1 : 0), "0");
	else
		new = ft_strdup(s + (*carryover ? 1 : 0));
	return (new);
}

void	divide_two(char **s)
{
	int		i;
	int		carryover;
	int		temp;
	char	*new;

	new = format_divide_string(*s, &carryover);
	i = -1;
	while (new[++i])
	{
		if (new[i] != '.')
		{
			temp = carryover;
			carryover = (new[i] - '0') % 2 * 10;
			new[i] = (new[i] - '0' + temp) / 2 + '0';
		}
	}
	free(*s);
	*s = new;
}

void	round_up(char **s)
{
	int		i;
	int		carryover;
	int		temp;
	char	*new;

	new = ft_strdup(*s);
	i = 0;
	while (new[i])
		i++;
	carryover = 1;
	while (--i >= 0 && carryover)
	{
		if (new[i] != '.')
		{
			temp = carryover;
			carryover = (new[i] - '0' + temp) / 10;
			new[i] = (new[i] - '0' + temp) % 10 + '0';
		}
	}
	if (carryover)
		new = ft_strjoin_free("1", new, 0, 1);
	free(*s);
	*s = new;
}
