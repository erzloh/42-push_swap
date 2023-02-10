/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:29:19 by eric              #+#    #+#             */
/*   Updated: 2023/02/09 16:41:50 by eholzer          ###   ########.fr       */
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
	int		*tab;
	int		size;
	char	arg_is_str;
	// int	first;
}	t_stack;

// Errors-handling functions
int		str_tab_len(char **str_tab);
void	check_is_arg_str(int *ac_ptr, char ***av_ptr, t_stack *stack_a);
int		check_input_errors(int ac, char **av, t_stack *stack_a);
int		check_digits(int ac, char **av);
double	check_int_max_atoi(const char *str);

// Utils functions
void	free_2d_tab(char **av, t_stack *stack_a);
void	init_stacks(int ac, char **av, t_stack *stack_a, t_stack *stack_b);
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

// Old algorithm functions
void	push_swap_algo(t_stack *stack_a, t_stack *stack_b);
int		find_right_place(t_stack *stack_a, t_stack *stack_b);
int		setup_stack_b(t_stack *stack_b, int right_place);
void	put_to_right_place(t_stack *stack_b, int tail);
void	push_all_to_a(t_stack *stack_a, t_stack *stack_b);

// New algorithm functions
void	small_numbers_sort(t_stack *stack_a, t_stack *stack_b);
void	three_numbers_sort(t_stack *stack_a);
void	pb_smallest_number(t_stack *stack_a, t_stack *stack_b);
void	make_tab_postive(t_stack *stack_a);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif