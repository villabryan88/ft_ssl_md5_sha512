/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 23:43:58 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/04 19:30:51 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_splitstr(char **src, char **front, int loc)
{
	char	*newsrc;
	int		newsrclen;

	newsrclen = ft_strlen(*src) - loc;
	*front = (char*)malloc(loc + 1);
	newsrc = (char*)malloc(newsrclen > 0 ? newsrclen : 1);
	ft_strncpy(*front, *src, loc);
	front[0][loc] = '\0';
	if (newsrclen)
		ft_strcpy(newsrc, *src + loc + 1);
	else
		newsrc[0] = '\0';
	free(*src);
	*src = newsrc;
	return (*src);
}
