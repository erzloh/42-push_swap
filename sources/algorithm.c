/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/21 20:56:13 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// General idea: Take each element of A and put it in B, where each new
// element in B is put at the right place. B is ordered from biggest to
// smallest. THen all the elements from B are pushed back to A.

// 1)	Look for the right place in stack B for the current first element
//		of stack A.
//
// 2) 	Setup B in such a way that we can push the element from A to B,
//		where the element is at the correct place and we just have to
//		rotate the elements to the top to get everything in place in B.
//
// 3)	Push the first element from A to B.
//
// 4)	Put the pushed element, that is currently at the top of B, to the
//		right place.
//
// 5)	Repeat until there are no elements left in A.
//
// 6)	Push every thing back to A.

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

int	setup_stack_b(t_stack *stack_b, int right_place, int *instructions)
{
	int	tail;
	int	i;

	tail = stack_b->size - right_place;
	i = 0;
	while (i < tail)
	{
		rrb(stack_b, instructions);
		i++;
	}
	return (tail);
}

void	put_to_right_place(t_stack *stack_b, int tail, int *instructions)
{
	int	i;

	i = 0;
	tail++;
	while (i < tail)
	{
		rb(stack_b, instructions);
		i++;
	}
}

void	push_all_to_a(t_stack *stack_a, t_stack *stack_b, int *instructions)
{
	int	i;
	int	intial_b_size;

	i = 0;
	intial_b_size = stack_b->size;
	while (i < intial_b_size)
	{
		pa(stack_a, stack_b, instructions);
		i++;
	}
}

void	push_swap_algo(t_stack *stack_a, t_stack *stack_b, int *instructions)
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
			pb(stack_a, stack_b, instructions);
			i++;
			continue ;
		}
		tail = setup_stack_b(stack_b, right_place, instructions);
		pb(stack_a, stack_b, instructions);
		put_to_right_place(stack_b, tail, instructions);
		i++;
	}
	push_all_to_a(stack_a, stack_b, instructions);
}
