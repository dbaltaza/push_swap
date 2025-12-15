/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:25:51 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:49 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(int *arr, int size, int value)
{
	int	rank;
	int	i;

	rank = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] < value)
			rank++;
		i++;
	}
	return (rank);
}

void	normalize_stack(t_stack *a)
{
	int	*temp;
	int	i;

	temp = malloc(sizeof(int) * a->size);
	if (!temp)
		return ;
	i = 0;
	while (i < a->size)
	{
		temp[i] = a->array[i];
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		a->array[i] = get_rank(temp, a->size, temp[i]);
		i++;
	}
	free(temp);
}

int	get_position(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_max_index(t_stack *a)
{
	int	i;
	int	max_idx;

	max_idx = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->array[i] > a->array[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}
