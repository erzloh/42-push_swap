/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:06:56 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/10 14:48:52 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digits(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (av[j][0] == '-' && av[j][1])
			i++;
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i]))
				return (ERROR);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_doubles(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 1;
		while (j + i < ac)
		{
			if (ft_strcmp(av[j], av[j + i]) == 0)
				return (ERROR);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_int_max(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_int_max_atoi(av[i]) == 1)
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_input_errors(int ac, char **av, t_stack *stack_a)
{
	if (check_digits(ac, av) == ERROR
		|| check_int_max(ac, av) == ERROR
		|| check_doubles(ac, av))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (stack_a->arg_is_str)
			free_2d_tab(av, stack_a);
		return (ERROR);
	}
	return (0);
}
