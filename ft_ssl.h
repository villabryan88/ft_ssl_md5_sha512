/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:03:22 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/13 22:50:56 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <libft.h>
# define ERR -1

unsigned int	*set_s();
unsigned int	*set_k();
unsigned int	leftrotate (unsigned int x, unsigned int c);
unsigned int	*break_into_words(unsigned char *chunk);
unsigned char 	*md5(char *msg, char *file);
unsigned char	*eight_byte_big_endian(unsigned long long n);
void			print_buf_hex(unsigned char *buf);
#endif
