/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:31:21 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/10 15:47:26 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free elements of a 2D array
void	free_2d_tab(char **av, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size + 2)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

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
	if (stack_a->arg_is_str)
		free_2d_tab(av, stack_a);
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

// Return 1 if the stack is sorted, 0 if it's not
int	is_stack_sorted(t_stack stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a.size - 1)
	{
		if (stack_a.tab[i] > stack_a.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
