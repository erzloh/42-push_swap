/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:31:21 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/22 15:20:43 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialize the stack_a struct with its tab and its size
void	init_stacks(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	stack_a->size = ac - 1;
	stack_a->tab = malloc(sizeof(int) * stack_a->size);
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	stack_b->tab = NULL;
	stack_b->size = 0;
}

// Print the tab of stack
void	print_tab(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		ft_printf("%d\n", stack.tab[i]);
		i++;
	}
}
