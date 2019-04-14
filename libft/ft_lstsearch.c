/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:41:14 by bvilla            #+#    #+#             */
/*   Updated: 2019/02/20 14:10:34 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *list, void *needle, size_t size)
{
	int		val;

	val = ft_elemval(needle, size);
	while (list)
	{
		if (ft_elemval(list->content, list->content_size) == val)
			return (list);
		list = list->next;
	}
	return (NULL);
}
