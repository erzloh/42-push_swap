/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab_positive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:29:11 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/06 14:48:59 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_tab_postive(t_stack *stack_a)
{
	int	*positive_tab;
	int	i;
	int	j;
	int	pos;

	positive_tab = malloc(sizeof(int) * stack_a->size);
	if (positive_tab == NULL)
		return ;
	i = -1;
	while (++i < stack_a->size)
	{
		j = -1;
		pos = 0;
		while (++j < stack_a->size)
			if (stack_a->tab[j] < stack_a->tab[i])
				pos++;
		positive_tab[i] = pos;
	}
	free(stack_a->tab);
	stack_a->tab = positive_tab;
}
