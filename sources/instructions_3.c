/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:24:09 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/21 20:56:09 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b, int *instructions)
{
	rra(stack_a, instructions);
	rrb(stack_b, instructions);
	ft_printf("rrr\n");
	*instructions += 1;
}
