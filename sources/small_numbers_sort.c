/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:53:40 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/09 15:38:51 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Algorithm that simply handles each possibility
void	three_numbers_sort(t_stack *stack_a)
{
	if (stack_a->tab[0] < stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[0] < stack_a->tab[2])
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[1] < stack_a->tab[2]
		&& stack_a->tab[0] < stack_a->tab[2])
		sa(stack_a);
	if (stack_a->tab[0] < stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[0] > stack_a->tab[2])
		rra(stack_a);
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[1] < stack_a->tab[2]
		&& stack_a->tab[0] > stack_a->tab[2])
		ra(stack_a);
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[0] > stack_a->tab[2])
	{
		sa(stack_a);
		rra(stack_a);
	}
}

// Algorithm to find sort an small input of numbers
//
// Find the smallest number in A.
// Check whether the smallest number is in the first or second half of A.
// Make it to the top of A accordingly (with ra or rra).
// pb.
// Repeat until the size of A is 3.
// Apply three_numbers_sort().
// pa until B is empty.
// Algorithm to sort small numbers

void	pb_smallest_number(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min;
	int	rotate;

	i = -1;
	min = 0;
	while (++i < stack_a->size - 1)
		if (stack_a->tab[i] > stack_a->tab[i + 1])
			min = i + 1;
	if (min <= stack_a->size / 2)
	{
		rotate = min;
		while (rotate--)
			ra(stack_a);
	}
	else
	{
		rotate = stack_a->size - min;
		while (rotate--)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	small_numbers_sort(t_stack *stack_a, t_stack *stack_b)
{

	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->tab[0] > stack_a->tab[1])
			sa(stack_a);
	}
	else if (stack_a->size == 3)
		three_numbers_sort(stack_a);
	else
	{
		while (stack_a->size > 3)
			pb_smallest_number(stack_a, stack_b);
		three_numbers_sort(stack_a);
		while (stack_b->size)
			pa(stack_a, stack_b);
	}
}
