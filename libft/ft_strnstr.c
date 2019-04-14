/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:22:30 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 17:47:53 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (len && len - i && haystack[i] == needle[i] && needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char*)haystack);
		len--;
		if (len == 0)
			return (NULL);
		haystack++;
	}
	return (NULL);
}
