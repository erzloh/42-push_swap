/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:42:30 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/06 17:26:17 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b, int *instructions)
{
	int	size;
	int	i;
	int	n;
	int	max_num;
	int	max_bit;

	size = stack_a->size;
	n = 0;
	max_num = size - 1;
	max_bit = 0;
	while (max_num != 0)
	{
		max_bit++;
		max_num = max_num >> 1;
	}
	ft_printf("max_bit=%d", max_bit);
	while (n < max_bit)
	{
		i = -1;
		while (++i < size)
		{
			if (((stack_a->tab[0] >> n) & 1) == 0)
				pb(stack_a, stack_b, instructions);
			ra(stack_a, instructions);
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b, instructions);
		n++;
	}
}
