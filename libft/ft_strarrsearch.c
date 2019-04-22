/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrsearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:10:32 by bvilla            #+#    #+#             */
/*   Updated: 2019/04/22 13:13:56 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strarrsearch(char **haystack, char *needle)
{
	while (*haystack)
	{
		if (ft_strequ(*haystack, needle))
			return (*haystack);
		haystack++;
	}
	return (NULL);
}
