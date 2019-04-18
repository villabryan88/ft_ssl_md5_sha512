/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:03:22 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/17 17:10:34 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <libft.h>
# define ERR -1
# define BUF_SIZE 64

typedef int (*t_hash)(char*, int, char**);

typedef struct 	s_flag 	{
	char		stdin_done;
	char		printed;
	char		*file_name;
	char		q;
	char		r;
}				t_flag;

unsigned int	*set_s();
unsigned int	*set_k();
unsigned int	ltrot(unsigned int x, unsigned int c);
unsigned int	rtrot(unsigned int x, unsigned int c);
unsigned int	*break_into_words(unsigned char *chunk);
int				md5(char *msg, int fd, char **digest);
int				get_next_chunk(char *msg, int fd, unsigned char *buf);
unsigned char	*eight_byte_big_endian(unsigned long long n);
int				sha256(char *msg, int fd, char **digest);
char	*digest_to_string(unsigned char *digest, int n);
void			reverse_bytes(void *str, size_t n);
#endif
