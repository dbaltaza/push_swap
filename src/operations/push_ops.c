/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:30:00 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:35 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size < 1)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = b->array[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->size--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size < 1)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = a->array[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->size--;
	ft_putstr_fd("pb\n", 1);
}
