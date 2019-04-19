/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:12:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/18 23:54:42 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int		print_error(t_error err, char **av, int j)
{
	if (err == illegal_option)
		ft_printf("%s: illegal option -- %c\n", av[1], *av[j]);
	if (err == no_s_argument)
		ft_printf("%s: option requires an argument --s\n", av[1]);
	if (err == invalid_command)
		ft_printf("ft_ssl: %s: invalid command\n\n"
				"Standard commands:\n\n"
				"Message Digest commands:\n"
				"md5\n"
				"sha224\n"
				"sha256\n\n"
				"Cipher commands:\n", av[1]);
	return (ERR);
}

void	print_digest(char *hash_alg, char *msg, int fd)
{
	char	*digest;
	int		err;

	err = hash_dispatcher(hash_alg)(msg, fd, &digest);
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
		{
			if (msg)
				ft_printf("%s (\"%s\") = ", hash_alg_upper, msg);
			else
				ft_printf("%s (%s) = ", hash_alg_upper, flags->file_name);
		}
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

void	print_usage(void)
{
	ft_printf("usage: ft_ssl command  [command opts] [command args]\n");
}
