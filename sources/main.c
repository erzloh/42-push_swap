/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:31:08 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/09 11:58:48 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	check_is_arg_str(&ac, &av, &stack_a);
	if (check_errors(ac, av) == ERROR)
		return (1);
	init_stacks(ac, av, &stack_a, &stack_b);

	if (stack_a.size <= 5)
		small_numbers_sort(&stack_a, &stack_b);
	else
	{
		make_tab_postive(&stack_a);
		radix_sort(&stack_a, &stack_b);
	}

	// ft_printf("STACK A ----------\n");
	// print_tab(stack_a);
	// ft_printf("STACK B ----------\n");
	// print_tab(stack_b);

	// free(stack_a.tab);
	// free(stack_b.tab);
	return (0);
}

// ft_printf("STACK A ----------\n");
// print_tab(stack_a);
// ft_printf("STACK B ----------\n");
// print_tab(stack_b);