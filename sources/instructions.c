/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:48:34 by eric              #+#    #+#             */
/*   Updated: 2023/01/14 18:06:59 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *elem1_ptr)
{
	t_list	elem1;
	t_list	elem2;
	
	elem1 = *elem1_ptr;
	elem2 = *elem1_ptr->next;

	elem1.next = elem2.next;
	elem2.next = elem1_ptr;
}