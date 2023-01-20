/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:29:19 by eric              #+#    #+#             */
/*   Updated: 2023/01/21 00:26:32 by eric             ###   ########.fr       */
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
int		check_errors(int ac, char **av);
int		check_digits(int ac, char **av);
double	check_int_max_atoi(const char *str);

// Utils functions
void	init_stack_a(int ac, char **av, t_stack *stack_a);
void	print_tab(t_stack stack);

// Instruction functions
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Algorithm functions
int		find_right_place(t_stack *stack_a, t_stack *stack_b);
int		setup_stack_b(t_stack *stack_b, int right_place);
void	put_to_right_place(t_stack *stack_b, int tail);
void	push_swap_algo(t_stack *stack_a, t_stack *stack_b);
void	push_all_to_a(t_stack *stack_a, t_stack *stack_b);

#endif