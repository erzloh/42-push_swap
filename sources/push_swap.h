/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:29:19 by eric              #+#    #+#             */
/*   Updated: 2023/01/23 15:39:27 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Import the libft, a library with basic C functions.
# include "../libft/libft.h"

// Define macros
# define ERROR 1

// Struct
typedef struct s_stack
{
	int	*tab;
	int	size;
}	t_stack;

// Errors-handling functions
int		str_tab_len(char **str_tab);
void	check_is_arg_str(int *ac_ptr, char ***av_ptr);
int		check_errors(int ac, char **av);
int		check_digits(int ac, char **av);
double	check_int_max_atoi(const char *str);

// Utils functions
void	init_stacks(int ac, char **av, t_stack *stack_a, t_stack *stack_b);
void	print_tab(t_stack stack);

// Instruction functions
void	sa(t_stack *stack_a, int *instructions);
void	sb(t_stack *stack_b, int *instructions);
void	ss(t_stack *stack_a, t_stack *stack_b, int *instructions);
void	pa(t_stack *stack_a, t_stack *stack_b, int *instructions);
void	pb(t_stack *stack_a, t_stack *stack_b, int *instructions);
void	ra(t_stack *stack_a, int *instructions);
void	rb(t_stack *stack_b, int *instructions);
void	rr(t_stack *stack_a, t_stack *stack_b, int *instructions);
void	rra(t_stack *stack_a, int *instructions);
void	rrb(t_stack *stack_b, int *instructions);
void	rrr(t_stack *stack_a, t_stack *stack_b, int *instructions);

// Algorithm functions
void	push_swap_algo(t_stack *stack_a, t_stack *stack_b, int *instructions);
int		find_right_place(t_stack *stack_a, t_stack *stack_b);
int		setup_stack_b(t_stack *stack_b, int right_place, int *instructions);
void	put_to_right_place(t_stack *stack_b, int tail, int *instructions);
void	push_all_to_a(t_stack *stack_a, t_stack *stack_b, int *instructions);

#endif