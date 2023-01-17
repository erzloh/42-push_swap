/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:31:08 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/17 14:34:07 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack_a(ac, av, &stack_a);
	stack_b.tab = NULL;
	stack_b.size = 0;
	// sa(&stack_a);
	// pb(&stack_a, &stack_b);
	ra(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	rb(&stack_b);
	ft_printf("STACK A ----------\n");
	print_tab(stack_a);
	ft_printf("STACK B ----------\n");
	print_tab(stack_b);
	free(stack_a.tab);
	free(stack_b.tab);
	return (0);
}
