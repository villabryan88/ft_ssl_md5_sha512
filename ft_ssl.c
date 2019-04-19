/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:06:17 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/18 23:47:38 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

t_cmd	dispatcher(char *cmd)
{
	if (hash_dispatcher(cmd))
		return (do_hash_cmd);
	else
		return (invalid_cmd);
}

char	*stdin_to_string(void)
{
	char	buf[1025];
	char	*str;

	buf[1024] = 0;
	str = ft_strdup("");
	while (read(0, buf, 1024))
		str = ft_strjoin_free(str, buf, 1, 0);
	return (str);
}

void	invalid_cmd(int ac, char **av)
{
	ac++;
	print_error(invalid_command, av, 0);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		print_usage();
	if (ac >= 2)
		dispatcher(av[1])(ac, av);
	return (0);
}
