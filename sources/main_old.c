/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:28:54 by eric              #+#    #+#             */
/*   Updated: 2023/01/16 10:07:33 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_arg_tab(int ac, char **av)
{
	int	*stack_a;
	int	i;

	stack_a = malloc(sizeof(int) * ac - 1);
	i = 0;
	while (i < ac - 1)
	{
		stack_a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (stack_a);
}

void	print_args(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*node_a;
	int		i;
	int	*arg_array;

	arg_array = get_arg_tab(ac, av);
	node_a = ft_lstnew(&arg_array[0]);
	print_args(arg_array, ac - 1);
	i = 1;
	while (i < ac - 1)
	{
		node_a->next = ft_lstnew(&arg_array[i]);
		node_a = node_a->next;
		i++;
	}
	node_a->next = NULL;

	return (0);
}
