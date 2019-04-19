/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:05:10 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/18 23:25:42 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

t_hash	hash_dispatcher(char *hash_alg)
{
	if (ft_strequ(hash_alg, "md5"))
		return (md5);
	else if (ft_strequ(hash_alg, "sha256"))
		return (sha256);
	else if (ft_strequ(hash_alg, "sha224"))
		return (sha224);
	return (NULL);
}

void	do_files(char **av, int *j, t_flag *flags)
{
	int		fd;

	fd = open(av[*j], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ft_ssl: %s: %s: No such file or directory or can't access\n",
					av[1], av[*j]);
		flags->printed = 1;
	}
	else
	{
		flags->file_name = av[*j];
		print_formatted_digest(flags, av[1], NULL, fd);
	}
	(*j)++;
}

void	do_hash_cmd(int ac, char **av)
{
	t_flag			flags;
	int				err;
	void			*tmp;
	int				j;

	ft_bzero(&flags, sizeof(flags));
	err = 0;
	j = 2;
	if (j < ac && *av[j] == '-')
		err = do_flags(ac, av, &j, &flags);
	while (!err && j < ac)
		do_files(av, &j, &flags);
	if (!err && ac >= 2 && !flags.printed)
	{
		flags.q = 1;
		tmp = stdin_to_string();
		print_formatted_digest(&flags, av[1], tmp, -2);
		free(tmp);
	}
}
