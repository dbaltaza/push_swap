/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:11:50 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:46 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack *a, t_stack *b)
{
	int	a_idx;
	int	b_idx;

	a_idx = find_cheapest_in_a(a, b);
	b_idx = find_target_in_b(b, a->array[a_idx]);
	do_rotations(a, b, a_idx, b_idx);
	pb(a, b);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	if (a->size > 3 && !is_sorted(a))
		pb(a, b);
	if (a->size > 3 && !is_sorted(a))
		pb(a, b);
	while (a->size > 3 && !is_sorted(a))
		push_to_b(a, b);
	sort_three(a);
	push_all_to_a(a, b);
	rotate_to_pos(a, find_min_index(a));
}
