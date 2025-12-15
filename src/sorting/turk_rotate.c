/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:30:00 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:45 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_to_pos(t_stack *a, int *a_idx)
{
	while (*a_idx > 0 && *a_idx <= a->size / 2)
	{
		ra(a);
		(*a_idx)--;
	}
	while (*a_idx < a->size && *a_idx > a->size / 2)
	{
		rra(a);
		(*a_idx)++;
	}
}

static void	rotate_b_to_pos(t_stack *b, int *b_idx)
{
	while (*b_idx > 0 && *b_idx <= b->size / 2)
	{
		rb(b);
		(*b_idx)--;
	}
	while (*b_idx < b->size && *b_idx > b->size / 2)
	{
		rrb(b);
		(*b_idx)++;
	}
}

void	do_rotations(t_stack *a, t_stack *b, int a_idx, int b_idx)
{
	int	a_top;
	int	b_top;

	a_top = (a_idx <= a->size / 2);
	b_top = (b_idx <= b->size / 2);
	while (a_top && b_top && a_idx > 0 && b_idx > 0)
	{
		rr(a, b);
		a_idx--;
		b_idx--;
	}
	while (!a_top && !b_top && a_idx < a->size && b_idx < b->size)
	{
		rrr(a, b);
		a_idx++;
		b_idx++;
	}
	rotate_a_to_pos(a, &a_idx);
	rotate_b_to_pos(b, &b_idx);
}

void	rotate_to_pos(t_stack *a, int idx)
{
	if (idx <= a->size / 2)
	{
		while (idx-- > 0)
			ra(a);
	}
	else
	{
		while (idx++ < a->size)
			rra(a);
	}
}

void	push_all_to_a(t_stack *a, t_stack *b)
{
	int	target_idx;

	while (b->size > 0)
	{
		target_idx = find_target_in_a(a, b->array[0]);
		rotate_to_pos(a, target_idx);
		pa(a, b);
	}
}
