/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:21:15 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/13 19:27:23 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <strings.h>

int		get_next_chunk(char *msg, int fd, char*buf);

int		main()
{
	char str[] = "I really wonder if this is going to work.";
	char buf[2];

	bzero(buf, 2);
	while (get_next_chunk(str, -2, buf) > 0)
	{
		write(1, buf, 2);
	}
	char str2[] = "Yeah BOI! I'm a mutha fucking GENIUS!!!!!!!!!!!!!!!!!!!";
	while (get_next_chunk(str2, -2, buf) > 0)
	{
		write(1, buf, 2);
	}
	return (0);
}
