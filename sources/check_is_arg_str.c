/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_arg_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:59:24 by eric              #+#    #+#             */
/*   Updated: 2023/02/10 15:05:07 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_tab_len(char **str_tab)
{
	int	i;

	i = 0;
	while (str_tab[i])
	{
		i++;
	}
	return (i);
}

void	create_new_av(int *ac_ptr, char ***av_ptr, int args_size, char **args)
{
	char	**new_av;
	int		i;

	new_av = malloc(sizeof(char *) * (args_size + 2));
	i = 0;
	new_av[0] = 0;
	while (i < args_size)
	{
		new_av[i + 1] = args[i];
		i++;
	}
	new_av[args_size + 1] = 0;
	*ac_ptr = args_size + 1;
	*av_ptr = new_av;
	free(args);
}

// Return 0 if there is a malloc error, 
// if there are no elements in the string argument,
// if there are not exactly 2 arguments.
void	check_is_arg_str(int *ac_ptr, char ***av_ptr, t_stack *stack_a)
{
	char	**args;
	int		args_size;

	stack_a->arg_is_str = 0;
	if (*ac_ptr != 2)
		return ;
	args = ft_split((*av_ptr)[1], ' ');
	args_size = str_tab_len(args);
	if (args_size > 1)
	{
		create_new_av(ac_ptr, av_ptr, args_size, args);
		stack_a->arg_is_str = 1;
		stack_a->size = args_size;
	}
	else
	{
		free(args[0]);
		free(args);
	}
}
