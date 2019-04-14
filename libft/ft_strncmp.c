/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:30:23 by bvilla            #+#    #+#             */
/*   Updated: 2018/10/30 18:38:38 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n)
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
			i++;
	else
		return (0);
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
