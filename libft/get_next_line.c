/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:22:24 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/15 18:42:21 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_more(char **dst, int fd)
{
	char	*new;
	int		result;
	int		len;

	len = ft_strlen(*dst);
	if (!(new = (char*)malloc(len + BUFF_SIZE + 1)))
		return (-1);
	if ((result = read(fd, new + len, BUFF_SIZE)) <= 0)
	{
		free(new);
		return (result);
	}
	new[len + result] = '\0';
	ft_strncpy(new, *dst, len);
	free(*dst);
	*dst = new;
	return (result);
}

t_list	*ft_lstfindsize(t_list *begin_list, size_t num)
{
	while (begin_list)
	{
		if (begin_list->content_size == num)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}

int		get_next_line_og(const int fd, char **line, char **main)
{
	int			result;
	char		*loc;

	result = 1;
	if (line == NULL)
		return (-1);
	if (*main == NULL)
		if (!(*main = ft_memalloc(1)))
			return (-1);
	while (!(loc = ft_strchr(*main, '\n')) && result > 0)
		if ((result = read_more(main, fd)) == -1)
			return (-1);
	if (result == 0 && **main == '\0')
		return (0);
	if (result != -1)
	{
		if (!loc)
			loc = *main + ft_strlen(*main);
		if (!(ft_splitstr(main, line, loc - *main)))
			return (-1);
	}
	return (result == -1 ? -1 : 1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*begin_list = NULL;
	int				ret;
	t_list			*loc;

	if (!(loc = ft_lstfindsize(begin_list, fd)))
	{
		if (!(loc = ft_lstnew(NULL, 0)))
			return (-1);
		loc->content_size = fd;
		ft_lstadd(&begin_list, loc);
	}
	ret = get_next_line_og(fd, line, (char**)&(loc->content));
	return (ret);
}
