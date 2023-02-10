/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:31:08 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/10 14:48:01 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	check_is_arg_str(&ac, &av, &stack_a);
	if (check_input_errors(ac, av, &stack_a) == ERROR)
		return (1);
	init_stacks(ac, av, &stack_a, &stack_b);
	if (is_stack_sorted(stack_a))
	{
		free(stack_a.tab);
		return (0);
	}
	if (stack_a.size <= 5)
		small_numbers_sort(&stack_a, &stack_b);
	else
	{
		make_tab_postive(&stack_a);
		radix_sort(&stack_a, &stack_b);
	}
	free(stack_a.tab);
	free(stack_b.tab);
	return (0);
}
