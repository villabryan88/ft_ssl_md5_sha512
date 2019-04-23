/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding512.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:32:43 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/23 13:20:12 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static int	do_padding(int red, unsigned long len[2], unsigned char *buf,
							t_end end)
{
	static int	append_started = 0;

	ft_bzero(buf + red, 128 - red);
	if (!append_started)
	{
		buf[red] = 128;
		append_started = 1;
	}
	if (red < 128 - 16)
	{
		*((unsigned long*)(buf + 128 - 16)) = len[0];
		*((unsigned long*)(buf + 128 - 8)) = len[1];
		if (end == big_end)
		{
			reverse_bytes(buf + BUF_SIZE - 16, 8);
			reverse_bytes(buf + BUF_SIZE - 8, 8);
		}
		append_started = 0;
		return (1);
	}
	return (0);
}

int			get_next_parsed_chunk1024(char *msg, int fd, unsigned char *buf,
									t_end end)
{
	int							red;
	static unsigned long		len[] = {0, 0};
	static int					padding_finished = 0;

	red = get_next_chunk(msg, fd, buf);
	if (red == -1)
		return (ERR);
	len[1] += red * 8;
	if (len[0] < red * 8lu)
		len[1]++;
	if (red < 128)
	{
		if (padding_finished)
		{
			padding_finished = 0;
			ft_bzero(len, sizeof(len));
			return (0);
		}
		padding_finished = do_padding(red, len, buf, end);
	}
	return (1);
}

int			get_next_chunk1024(char *msg, int fd, unsigned char *buf)
{
	static unsigned int	i = 0;
	static char			*curr_msg = NULL;
	unsigned int		len;

	if (fd >= 0)
		return (read(fd, buf, 128));
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
		if (len > 128)
			len = 128;
		ft_strncpy((char*)buf, msg + i, len);
		i += len;
		return (len);
	}
}
