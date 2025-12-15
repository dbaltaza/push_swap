/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:30:00 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:32 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->size - 1] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[b->size - 1] = temp;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size >= 2)
	{
		temp = a->array[0];
		i = -1;
		while (++i < a->size - 1)
			a->array[i] = a->array[i + 1];
		a->array[a->size - 1] = temp;
	}
	if (b->size >= 2)
	{
		temp = b->array[0];
		i = -1;
		while (++i < b->size - 1)
			b->array[i] = b->array[i + 1];
		b->array[b->size - 1] = temp;
	}
	ft_putstr_fd("rr\n", 1);
}
