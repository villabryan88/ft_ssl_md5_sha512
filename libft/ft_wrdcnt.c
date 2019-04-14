/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:55:46 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 22:03:20 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wrdcnt(char *s, char c)
{
	int				words;
	unsigned int	i;
	unsigned int	j;

	words = 0;
	i = -1;
	while (s && (j = (unsigned int)ft_strchr(s + (i + 1), (int)c)) &&
			(j - (unsigned int)s - i == 1 || ++words))
		i = j - (unsigned int)s;
	if (s && !j && ft_strlen(s + (i + 1)) > 0)
		words++;
	return (words);
}
