/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:06:17 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/16 22:13:23 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void print_digest(char *hash_alg, char *msg, int fd)
{
	char *digest;
	int		err;

	if (ft_strequ(hash_alg, "md5"))
		err = md5(msg, fd, &digest);
	else if (ft_strequ(hash_alg, "sha256"))
		err = sha256(msg, fd, &digest);
	else
	{
		ft_printf("ft_ssl: %s: invalid option\n", hash_alg);
		return ;
	}
	if (err == ERR)
	{
		ft_printf("error\n");
		return ;
	}
	ft_printf("%s\n", digest);
}

void		print_usage()
{
	ft_printf("usage: ft_ssl (sha256 | md5) [-r] [-q] [-s] [-p] \"string\" source_file");
}

int			main(int ac, char **av)
{
//	unsigned char 	*digest;
//	char			*msg;
	int				fd;
	int				j;

	if (ac == 1)
	{
		print_usage();
	}
/*	if (ac == 2)
	{
		msg = stdin_to_string();
		print_digest(av[1], msg, -2);
	}
*/	j = 2;
	while (j < ac)
	{
		fd = av[j] ? open(av[j], O_RDONLY) : -2;
		if (fd == -1)
		{
			ft_printf("error\n");
			return (0);
		}
		print_digest(av[1], NULL, fd);
		j++;
	}
	return (0);

}
