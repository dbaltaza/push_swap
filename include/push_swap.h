/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:25:25 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:33:10 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				*array;
	int				size;
	int				capacity;
}	t_stack;

/* Stack operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Utils */
t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *a);
void	error_exit(t_stack *a, t_stack *b);

/* Parsing */
int		parse_arguments(int argc, char **argv, t_stack *a, t_stack *b);
void	parse_split(char **split, t_stack *a, t_stack *b);

/* Index conversion */
void	normalize_stack(t_stack *a);

/* Sorting algorithms */
void	sort_stack(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

/* Cost-based sorting for larger stacks */
void	turk_sort(t_stack *a, t_stack *b);
int		find_target_in_a(t_stack *a, int b_value);
int		find_target_in_b(t_stack *b, int a_value);
int		calc_cost(int idx, int size);
int		get_total_cost(t_stack *a, t_stack *b, int a_idx, int b_idx);
int		find_cheapest_in_a(t_stack *a, t_stack *b);
void	do_rotations(t_stack *a, t_stack *b, int a_idx, int b_idx);
void	rotate_to_pos(t_stack *a, int idx);
void	push_all_to_a(t_stack *a, t_stack *b);

/* Helper functions */
int		find_min_index(t_stack *a);
int		find_max_index(t_stack *a);
int		get_position(t_stack *a, int value);

#endif