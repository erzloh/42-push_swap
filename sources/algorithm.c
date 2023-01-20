/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/20 18:32:07 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pb 
// find the right place for the newly added elem
// put the elem to the right place
// repeat until no elements are left on A
// pa all elements of b

int	find_right_place(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_b->size)
	{
		if (stack_b->tab[i] < stack_a->tab[0])
			break ;
		i++;
	}
	return (i);
}

int	setup_stack_b(t_stack *stack_b, int right_place)
{
	int	tail;
	int	i;

	tail = stack_b->size - right_place;
	i = 0;
	while (i < tail)
	{
		rrb(stack_b);
		i++;
	}
	return (tail);
}

void	put_to_right_place(t_stack *stack_b, int tail)
{
	int	i;

	i = 0;
	tail++;
	while (i < tail)
	{
		rb(stack_b);
		i++;
	}
}

void	push_swap_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	initial_a_size;
	int	right_place;
	int	tail;

	i = 0;
	initial_a_size = stack_a->size;
	while (i < initial_a_size)
	{
		right_place = find_right_place(stack_a, stack_b);
		if (right_place == 0)
		{
			pb(stack_a, stack_b);
			i++;
			continue ;
		}
		tail = setup_stack_b(stack_b, right_place);
		pb(stack_a, stack_b);
		put_to_right_place(stack_b, tail);
		i++;
	}
}
