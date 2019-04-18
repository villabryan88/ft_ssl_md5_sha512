/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:50:05 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/18 14:50:43 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int			do_padding(int red, int len, unsigned char *buf, t_end end)
{
	static int					append_started = 0;
	
	ft_bzero(buf + red, BUF_SIZE - red);
	if (!append_started)
	{
		buf[red] = 128;
		append_started = 1;
	}
	if (red < BUF_SIZE - 8)
	{
		*((unsigned long long *)(buf + BUF_SIZE - 8)) = len;
		if(end == big_end)
			reverse_bytes(buf + BUF_SIZE - 8, 8);
		append_started = 0;
		return (1);
	}
	return (0);
}
int			get_next_parsed_chunk(char *msg, int fd, unsigned char *buf,
									t_end end)
{
	int							red;
	static unsigned long long	len = 0;
	static int					padding_finished = 0;

	red = get_next_chunk(msg, fd, buf);
	if (red == -1)
		return (ERR);
	len += red * 8;
	if (red < BUF_SIZE)
	{
		if(padding_finished)
		{
			padding_finished = 0;
			len = 0;
			return (0);
		}
		padding_finished = do_padding(red, len, buf, end);
	}
	return (1);
}
int				get_next_chunk(char *msg, int fd, unsigned char *buf)
{
	static unsigned int	i = 0;
	static char			*curr_msg = NULL;
	unsigned int		len;


	if (fd >= 0)
		return(read(fd, buf, BUF_SIZE));
	else
	{
		if (curr_msg != msg)
		{
			i = 0;
			curr_msg = msg;
		}
		if (i >= ft_strlen(msg))
		{
			return (0);
		}
		len = ft_strlen(msg + i);
		if (len > BUF_SIZE)
			len = BUF_SIZE;
		ft_strncpy((char*)buf, msg + i, len);
		i += len;
		return (len);
	}
}
