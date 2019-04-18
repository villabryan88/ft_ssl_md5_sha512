/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:06:17 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/17 17:12:47 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

t_hash	dispatcher(char *hash_alg)
{
	if (ft_strequ(hash_alg, "md5"))
		return (md5);
	else if (ft_strequ(hash_alg, "sha256"))
		return (sha256);
	return (NULL);
}

void	print_digest(char *hash_alg, char *msg, int fd)
{
	char *digest;
	int		err;

	err = dispatcher(hash_alg)(msg, fd, &digest);
	if (err == ERR)
	{
		ft_printf("error");
		return ;
	}
	ft_printf("%s", digest);
	free(digest);
}

void	print_formatted_digest(t_flag *flags, char *hash_alg, char *msg, int fd)
{
		char	*hash_alg_upper;

		hash_alg_upper = ft_strdup(hash_alg);
		ft_strtoupper(hash_alg_upper);
		if (!flags->q)
		{
			if (!flags->r)
				ft_printf("%s (\"%s\") = ", hash_alg_upper, msg);
		}
		print_digest(hash_alg, msg, fd);
		if (!flags->q && flags->r)
		{
			if (msg)
				ft_printf(" \"%s\"", msg);
			else
				ft_printf(" %s", flags->file_name);
		}
		ft_printf("\n");
		free(hash_alg_upper);
		flags->printed = 1;
}

void		print_usage()
{
	ft_printf("usage: ft_ssl (sha256 | md5) [-pqr] [-s string] [files...]\n");
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

void		do_flags(int ac, char **av, int *i, t_flag *flags)
{
	char	*msg;
	char	*tmp;
	int		j;

	j = *i;
	while (j < ac && *av[j] == '-' )
	{
		while (*++av[j])
		{
			if (*av[j] == 'q')
				flags->q = 1;
			else if (*av[j] == 'r')
				flags->r = 1;
			else if (*av[j] == 'p')
			{
				if (!flags->stdin_done)
				{
					msg = stdin_to_string();
					tmp = ft_strsub(msg, 0, ft_strlen(msg) - 1);
					ft_putendl(tmp);
					print_digest(av[1], msg, -2);
					ft_putchar('\n');
					free(tmp);
					free(msg);
					flags->stdin_done = 1;
					flags->printed = 1;
				}
				else
					print_digest(av[1], "", -2);
			}
			else if (*av[j] == 's')
			{
				if(!*++av[j])
					j++;
				else if (j >= ac)
				{
					ft_printf("%s: option requires an argument --s\n", av[1]);
					print_usage();
				}
				msg = ft_strdup(av[j]);
				print_formatted_digest(flags, av[1], msg, -2);
				free(msg);
			}
		}
		j++;
	}	
	*i = j;
}

int			main(int ac, char **av)
{
	t_flag			flags;
	void			*tmp;
	int				fd;
	int				j;

	ft_bzero(&flags, sizeof(flags));
	if (ac == 1)
		print_usage();
	if (ac >= 2 && !dispatcher(av[1]))
	{
		ft_printf("ft_ssl: %s: invalid option\n", av[1]);
		print_usage();
		return (0);
	}

	j = 2;
	if (j < ac && *av[j] == '-') 
		do_flags(ac, av, &j, &flags);
	while (j < ac)
	{
		fd = open(av[j], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("error\n");
			return (0);
		}
		flags.file_name = av[j];
		print_formatted_digest(&flags, av[1], NULL, fd);
		j++;
	}
	if (ac >= 2 && !flags.printed)
	{
		flags.q = 1;
		tmp = stdin_to_string();
		print_formatted_digest(&flags, av[1], tmp, -2);
		free(tmp);
	}

	return (0);

}
