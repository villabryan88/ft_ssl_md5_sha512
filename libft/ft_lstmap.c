/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:49:32 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/05 21:54:11 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del(void *ptr, size_t size)
{
	t_list	*elem;

	elem = (t_list*)ptr;
	if (!elem)
		return ;
	elem->content_size = size;
	if (elem->content)
		free(elem->content);
	free(elem);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*i;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	i = new;
	lst = lst->next;
	while (lst)
	{
		i->next = f(lst);
		if (!i->next)
		{
			ft_lstdel(&new, *del);
			return (NULL);
		}
		i = i->next;
		lst = lst->next;
	}
	return (new);
}
