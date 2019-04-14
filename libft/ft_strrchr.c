/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:12:04 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 16:47:50 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *lst;

	lst = NULL;
	while (*s)
	{
		if (*s == (char)c)
			lst = (char*)s;
		s++;
	}
	lst = *s == (char)c ? (char*)s : lst;
	return (lst);
}
