/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:32:54 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/18 23:46:45 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void		do_p(char **av, t_flag *flags)
{
	char	*msg;
	char	*tmp;

	if (!flags->stdin_done)
	{
		tmp = stdin_to_string();
		msg = ft_strsub(tmp, 0, ft_strlen(tmp) - 1);
		ft_putendl(msg);
		print_digest(av[1], tmp, -2);
		ft_putchar('\n');
		free(tmp);
		free(msg);
		flags->stdin_done = 1;
		flags->printed = 1;
	}
	else
	{
		print_digest(av[1], "", -2);
		ft_putchar('\n');
	}
}

int			do_s(int ac, char **av, int *j, t_flag *flags)
{
	char	*msg;

	if (!*++av[*j])
		(*j)++;
	if (*j >= ac)
		return (print_error(no_s_argument, av, *j));
	msg = ft_strdup(av[*j]);
	while (*av[*j])
		av[*j]++;
	av[*j]--;
	print_formatted_digest(flags, av[1], msg, -2);
	free(msg);
	return (0);
}

int			do_flags(int ac, char **av, int *j, t_flag *flags)
{
	while (*j < ac && *av[*j] == '-')
	{
		while (*j < ac && *++av[*j])
		{
			if (*av[*j] == 'q')
				flags->q = 1;
			else if (*av[*j] == 'r')
				flags->r = 1;
			else if (*av[*j] == 'p')
				do_p(av, flags);
			else if (*av[*j] == 's')
			{
				if (do_s(ac, av, j, flags) == ERR)
					return (ERR);
			}
			else
				return (print_error(illegal_option, av, *j));
		}
		(*j)++;
	}
	return (0);
}
