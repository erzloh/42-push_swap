/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:53:40 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/07 16:49:32 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers_sort(t_stack *stack_a, int *instructions)
{
	if (stack_a->tab[0] < stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[0] < stack_a->tab[2])
	{
		sa(stack_a, instructions);
		ra(stack_a, instructions);
	}
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[1] < stack_a->tab[2]
		&& stack_a->tab[0] < stack_a->tab[2])
		sa(stack_a, instructions);
	if (stack_a->tab[0] < stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[0] > stack_a->tab[2])
		rra(stack_a, instructions);
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[1] < stack_a->tab[2]
		&& stack_a->tab[0] > stack_a->tab[2])
		ra(stack_a, instructions);
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[0] > stack_a->tab[2])
	{
		sa(stack_a, instructions);
		rra(stack_a, instructions);
	}
}

// Algorithm to sort small numbers (the algorithm for three numbers is simply handling each possibility)
void	small_numbers_sort(t_stack *stack_a, t_stack *stack_b, int *instructions)
{
	if (stack_a->size == 3)
		three_numbers_sort(stack_a, instructions);
	else
	{
		while (stack_a->size > 3)
			pb(stack_a, stack_b, instructions);
		three_numbers_sort(stack_a, instructions);
		push_swap_algo(stack_b, stack_a, instructions);
	}
}
