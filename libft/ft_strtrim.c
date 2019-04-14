/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 00:55:17 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 20:46:51 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (*s && *s <= ' ')
		s++;
	while (s[i])
		i++;
	while (i && s[i] <= ' ')
		i--;
	if (s[i])
		i++;
	return (ft_strsub(s, 0, i));
}