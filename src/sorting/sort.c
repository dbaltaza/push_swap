/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:25:49 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:43 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->array[0] > a->array[1])
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->array[0];
	second = a->array[1];
	third = a->array[2];
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_idx;

	min_idx = find_min_index(a);
	if (min_idx <= a->size / 2)
	{
		while (min_idx-- > 0)
			ra(a);
	}
	else
	{
		while (min_idx++ < a->size)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		turk_sort(a, b);
}
