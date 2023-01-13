/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:17:22 by eric              #+#    #+#             */
/*   Updated: 2022/11/02 15:58:01 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_lst_first_node;
	(void) del;

	while (lst)
	{
		(*f)(lst->content);
		new_lst = ft_lstnew(lst->content);
		if (!new_lst)
			return (NULL);
		if (!new_lst_first_node)
			new_lst_first_node = new_lst;
		lst = lst->next;
		new_lst = lst->next;
	}
	return (new_lst_first_node);
}