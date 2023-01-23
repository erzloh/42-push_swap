/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:31:08 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/23 16:04:49 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		instructions;

	check_is_arg_str(&ac, &av);
	if (check_errors(ac, av) == ERROR)
		return (1);
	init_stacks(ac, av, &stack_a, &stack_b);
	instructions = 0;
	push_swap_algo(&stack_a, &stack_b, &instructions);
	
	// ft_printf("STACK A ----------\n");
	// print_tab(stack_a);
	// ft_printf("STACK B ----------\n");
	// print_tab(stack_b);
	// ft_printf("instructions = %d\n", instructions);

	// free(stack_a.tab);
	// free(stack_b.tab);
	return (0);
 }
