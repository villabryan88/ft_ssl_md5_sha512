/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:06:17 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/15 21:29:45 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>


int		main(int ac, char **av)
{
	unsigned char *digest;
	int		i = 0;
	int				fd;

/*
	if (ac == 2)
	{
		fd = av[1] ? open(av[1], O_RDONLY) : -2;
		if (fd == -1)
		{
			ft_printf("error\n");
			return (0);
		}
	
		if (md5(NULL, fd, &digest) == ERR)
		{
			ft_printf("error\n");
			return (0);
		}
		while (i < 16)
		{
			ft_printf("%.2hhx", *(digest + i));
			i++;
		}

	}
*/
	if (ac == 2)
	{
		fd = av[1] ? open(av[1], O_RDONLY) : -2;
		if (fd == -1)
		{
			ft_printf("error\n");
			return (0);
		}
	
		if (sha256(NULL, fd, &digest) == ERR)
//		if (sha256(av[1], -2, &digest) == ERR)
		{
			ft_printf("error\n");
			return (0);
		}
		while (i < 8)
		{
			ft_printf("%.8x", ((unsigned int*)digest)[i]);
			i++;
		}

	}
	ft_printf("\n");
	return (0);

}
