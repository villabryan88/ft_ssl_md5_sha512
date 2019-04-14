/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:03:43 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/07 19:38:29 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*ret;
	unsigned int	i;

	if (s && f)
		i = ft_strlen(s);
	else
		return (NULL);
	if ((ret = (char*)malloc(i + 1)))
	{
		ret[i] = '\0';
		while (i--)
			ret[i] = f(s[i]);
		return (ret);
	}
	else
		return (NULL);
}
