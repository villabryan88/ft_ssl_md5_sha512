/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:21:15 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/13 22:35:19 by bvilla           ###   ########.fr       */
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

	unsigned long long num= 0x25461349f55a2c1b;
	digest = (unsigned char*)&num;
	while (i < 8){
		ft_printf("%.2hhx", *(digest + i));
		i++;
	}
	ft_printf("\n");
	i = 0;
	digest = eight_byte_big_endian(num);
	while (i < 8){
		ft_printf("%.2hhx", *(digest + i));
		i++;
	}
	return (0);
}
