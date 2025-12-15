/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:30:00 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:47 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_in_a(t_stack *a, int b_value)
{
	int	i;
	int	target_idx;
	int	closest;

	target_idx = find_min_index(a);
	closest = INT_MAX;
	i = 0;
	while (i < a->size)
	{
		if (a->array[i] > b_value && a->array[i] < closest)
		{
			closest = a->array[i];
			target_idx = i;
		}
		i++;
	}
	return (target_idx);
}

int	find_target_in_b(t_stack *b, int a_value)
{
	int	i;
	int	target_idx;
	int	closest;

	if (b->size == 0)
		return (0);
	target_idx = find_max_index(b);
	closest = INT_MIN;
	i = 0;
	while (i < b->size)
	{
		if (b->array[i] < a_value && b->array[i] > closest)
		{
			closest = b->array[i];
			target_idx = i;
		}
		i++;
	}
	return (target_idx);
}

int	calc_cost(int idx, int size)
{
	if (idx <= size / 2)
		return (idx);
	return (size - idx);
}

int	get_total_cost(t_stack *a, t_stack *b, int a_idx, int b_idx)
{
	int	cost_a;
	int	cost_b;
	int	both_top;
	int	both_bottom;

	cost_a = calc_cost(a_idx, a->size);
	cost_b = calc_cost(b_idx, b->size);
	both_top = (a_idx <= a->size / 2 && b_idx <= b->size / 2);
	both_bottom = (a_idx > a->size / 2 && b_idx > b->size / 2);
	if (both_top || both_bottom)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

int	find_cheapest_in_a(t_stack *a, t_stack *b)
{
	int	i;
	int	cheapest_idx;
	int	min_cost;
	int	cost;
	int	target_b;

	cheapest_idx = 0;
	min_cost = INT_MAX;
	i = 0;
	while (i < a->size)
	{
		target_b = find_target_in_b(b, a->array[i]);
		cost = get_total_cost(a, b, i, target_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_idx = i;
		}
		i++;
	}
	return (cheapest_idx);
}
