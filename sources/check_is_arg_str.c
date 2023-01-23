/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_arg_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:59:24 by eric              #+#    #+#             */
/*   Updated: 2023/01/23 16:23:44 by eric             ###   ########.fr       */
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

// Return 0 if there is a malloc error, 
// if there are no elements in the string argument,
// if there are not exactly 2 arguments.
void	check_is_arg_str(int *ac_ptr, char ***av_ptr)
{
	char	**args;
	int		args_size;
	char	**new_av;
	int		i;

	if (*ac_ptr != 2)
		return ;
	args = ft_split((*av_ptr)[1], ' ');
	args_size = str_tab_len(args);
	if (args_size > 1)
	{
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
	}
}
