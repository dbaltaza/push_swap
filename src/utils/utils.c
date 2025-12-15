/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:25:47 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:50 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->array);
		free(stack);
	}
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (!a || a->size <= 1)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->array[i] > a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	find_min_index(t_stack *a)
{
	int	i;
	int	min_idx;

	min_idx = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->array[i] < a->array[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}
