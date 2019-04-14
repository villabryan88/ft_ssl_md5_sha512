/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:49:51 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 16:38:32 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = ft_strnlen(dst, dstsize);
	dstsize -= dlen;
	dst += dlen;
	if (dstsize)
	{
		while (*src && --dstsize)
			*(dst++) = *(src++);
		*dst = '\0';
	}
	return (dlen + slen);
}
