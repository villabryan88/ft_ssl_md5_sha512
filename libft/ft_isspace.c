/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:08:32 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 19:16:14 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	unsigned char l;

	l = (unsigned char)c;
	if (l == (unsigned char)'\t' || l == (unsigned char)'\n'
			|| l == (unsigned char)'\v' || l == (unsigned char)'\f'
				|| l == (unsigned char)'\r' || l == (unsigned char)' ')
		return (1);
	return (0);
}
