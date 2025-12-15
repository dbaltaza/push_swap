/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:30:00 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:33 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->array[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->array[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size >= 2)
	{
		temp = a->array[a->size - 1];
		i = a->size;
		while (--i > 0)
			a->array[i] = a->array[i - 1];
		a->array[0] = temp;
	}
	if (b->size >= 2)
	{
		temp = b->array[b->size - 1];
		i = b->size;
		while (--i > 0)
			b->array[i] = b->array[i - 1];
		b->array[0] = temp;
	}
	ft_putstr_fd("rrr\n", 1);
}
