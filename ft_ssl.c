/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:06:17 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/17 23:12:56 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int		print_error(t_error err, char **av, int j)
{
	if(err == illegal_option)
		ft_printf("%s: illegal option -- %c\n", av[1], *av[j]);
	if(err == no_s_argument)
		ft_printf("%s: option requires an argument --s\n", av[1]);
	if(err == invalid_command)
		ft_printf("ft_ssl: %s: invalid command\n\n"
				"Standard commands:\n\n"
				"md5 [-pqr] [-s string] [files..]\n"
				"sha256 [-pqr] [-s string] [files..]\n\n"
				"Cipher commands:\n", av[1]);
	return (ERR);
}

char 	*stdin_to_string()
{
	char	buf[1025];
	char	*str;

	buf[1024] = 0;
	str = ft_strdup("");
	while(read(0, buf, 1024))
		str = ft_strjoin_free(str, buf, 1, 0);

	return (str);
}

void		do_files(char **av, int *j, t_flag *flags)
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

int			main(int ac, char **av)
{
	t_flag			flags;
	int				err;
	void			*tmp;
	int				j;

	ft_bzero(&flags, sizeof(flags));
	err = 0;
	if (ac == 1)
		print_usage();
	if (ac >= 2 && !dispatcher(av[1]))
		return(print_error(invalid_command, av, 0));
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
	return (0);
}
