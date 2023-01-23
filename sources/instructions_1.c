/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:32:06 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/21 20:57:53 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int *instructions)
{
	int	tmp;

	if (stack_a->size >= 2)
	{
		tmp = stack_a->tab[0];
		stack_a->tab[0] = stack_a->tab[1];
		stack_a->tab[1] = tmp;
		ft_printf("sa\n");
		*instructions += 1;
	}
}

void	sb(t_stack *stack_b, int *instructions)
{
	int	tmp;

	if (stack_b->size >= 2)
	{
		tmp = stack_b->tab[0];
		stack_b->tab[0] = stack_b->tab[1];
		stack_b->tab[1] = tmp;
		ft_printf("sb\n");
		*instructions += 1;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, int *instructions)
{
	sa(stack_a, instructions);
	sb(stack_b, instructions);
	ft_printf("ss\n");
	*instructions += 1;
}

void	pa(t_stack *stack_a, t_stack *stack_b, int *instructions)
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
	ft_printf("pa\n");
	*instructions += 1;
}

void	pb(t_stack *stack_a, t_stack *stack_b, int *instructions)
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
	ft_printf("pb\n");
	*instructions += 1;
}
