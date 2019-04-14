/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:50:07 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 20:59:05 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int				words;
	int				wnum;
	unsigned int	i;
	unsigned int	j;
	char			**arr;

	words = 0;
	wnum = 0;
	i = -1;
	while (s && (j = (unsigned int)ft_strchr(s + (i + 1), (int)c)) &&
			(j - (unsigned int)s - i == 1 || ++words))
		i = j - (unsigned int)s;
	if (s && !j && ft_strlen(s + (i + 1)) > 0)
		words++;
	if (!(arr = (char**)malloc(sizeof(arr) * (words + 1))))
		return (NULL);
	i = -1;
	while (s && (j = (unsigned int)ft_strchr(s + (i + 1), (int)c)) &&
			(j - (unsigned int)s - i == 1 || (words-- && (arr[wnum++] =
				ft_strsub(s, i + 1, j - (unsigned int)s - i - 1)))))
		i = j - (unsigned int)s;
	if (s && !j && ft_strlen(s + (i + 1)) > 0)
		arr[wnum++] = ft_strdup(s + (i + 1));
	arr[wnum] = 0;
	return (arr);
}
