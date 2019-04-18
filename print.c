/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:12:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/17 23:31:19 by bvilla           ###   ########.fr       */
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

void		print_usage()
{
	ft_printf("usage: ft_ssl command  [command opts] [command args]\n");
}
