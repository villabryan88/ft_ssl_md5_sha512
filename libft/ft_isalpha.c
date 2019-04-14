/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:12:03 by bvilla            #+#    #+#             */
/*   Updated: 2018/10/31 12:56:41 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	unsigned char l;

	l = (unsigned char)c;
	if ((c >= (unsigned char)'a' && c <= (unsigned char)'z') ||
		(c >= (unsigned char)'A' && c <= (unsigned char)'Z'))
		return (1);
	return (0);
}
