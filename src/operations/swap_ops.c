/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:30:00 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:28 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	b->array[0] = b->array[1];
	b->array[1] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size >= 2)
	{
		temp = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = temp;
	}
	if (b->size >= 2)
	{
		temp = b->array[0];
		b->array[0] = b->array[1];
		b->array[1] = temp;
	}
	ft_putstr_fd("ss\n", 1);
}
