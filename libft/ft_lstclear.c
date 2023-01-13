/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:36:48 by eric              #+#    #+#             */
/*   Updated: 2022/11/02 15:11:25 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;
	t_list *next;

	node = *lst;
	while (node)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = node->next;
	}
	*lst = NULL;
}
