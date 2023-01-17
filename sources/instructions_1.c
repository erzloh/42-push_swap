/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:32:06 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/17 14:28:06 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size >= 2)
	{
		tmp = stack_a->tab[0];
		stack_a->tab[0] = stack_a->tab[1];
		stack_a->tab[1] = tmp;
	}
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size >= 2)
	{
		tmp = stack_b->tab[0];
		stack_b->tab[0] = stack_b->tab[1];
		stack_b->tab[1] = tmp;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	*new_stack_a;
	int	*new_stack_b;
	int	i;

	if (stack_b->size == 0)
		return ;
	new_stack_a = malloc(sizeof(int) * (stack_a->size + 1));
	new_stack_b = malloc(sizeof(int) * (stack_b->size - 1));
	i = -1;
	while (++i < stack_a->size)
		new_stack_a[i + 1] = stack_a->tab[i];
	new_stack_a[0] = stack_b->tab[0];
	i = -1;
	while (++i < stack_b->size - 1)
		new_stack_b[i] = stack_b->tab[i + 1];
	free(stack_a->tab);
	free(stack_b->tab);
	stack_a->tab = new_stack_a;
	stack_b->tab = new_stack_b;
	stack_a->size++;
	stack_b->size--;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	*new_stack_a;
	int	*new_stack_b;
	int	i;

	if (stack_a->size == 0)
		return ;
	new_stack_a = malloc(sizeof(int) * (stack_a->size - 1));
	new_stack_b = malloc(sizeof(int) * (stack_b->size + 1));
	i = -1;
	while (++i < stack_b->size)
		new_stack_b[i + 1] = stack_b->tab[i];
	new_stack_b[0] = stack_a->tab[0];
	i = -1;
	while (++i < stack_a->size - 1)
		new_stack_a[i] = stack_a->tab[i + 1];
	free(stack_a->tab);
	free(stack_b->tab);
	stack_a->tab = new_stack_a;
	stack_b->tab = new_stack_b;
	stack_a->size--;
	stack_b->size++;
}
