/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:42:30 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/10 15:15:37 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;
	int	n;
	int	max_num;
	int	max_bit;

	size = stack_a->size;
	n = -1;
	max_num = size - 1;
	max_bit = 0;
	while (max_num >> max_bit != 0)
		max_bit++;
	while (++n < max_bit)
	{
		i = -1;
		while (++i < size)
		{
			if (((stack_a->tab[0] >> n) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
	}
}
