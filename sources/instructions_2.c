/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:41:52 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/21 20:55:56 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int *instructions)
{
	int	tmp;
	int	i;

	if (stack_a->size < 2)
		return ;
	tmp = stack_a->tab[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[stack_a->size - 1] = tmp;
	ft_printf("ra\n");
	*instructions += 1;
}

void	rb(t_stack *stack_b, int *instructions)
{
	int	tmp;
	int	i;

	if (stack_b->size < 2)
		return ;
	tmp = stack_b->tab[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	stack_b->tab[stack_b->size - 1] = tmp;
	ft_printf("rb\n");
	*instructions += 1;
}

void	rr(t_stack *stack_a, t_stack *stack_b, int *instructions)
{
	ra(stack_a, instructions);
	rb(stack_b, instructions);
	ft_printf("rr\n");
	*instructions += 1;
}

void	rra(t_stack *stack_a, int *instructions)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_a->size;
	if (size < 2)
		return ;
	tmp = stack_a->tab[size - 1];
	i = 0;
	while (i < size - 1)
	{
		stack_a->tab[size - 1 - i] = stack_a->tab[size - 1 - i - 1];
		i++;
	}
	stack_a->tab[0] = tmp;
	ft_printf("rra\n");
	*instructions += 1;
}

void	rrb(t_stack *stack_b, int *instructions)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_b->size;
	if (size < 2)
		return ;
	tmp = stack_b->tab[size - 1];
	i = 0;
	while (i < size - 1)
	{
		stack_b->tab[size - 1 - i] = stack_b->tab[size - 1 - i - 1];
		i++;
	}
	stack_b->tab[0] = tmp;
	ft_printf("rrb\n");
	*instructions += 1;
}
