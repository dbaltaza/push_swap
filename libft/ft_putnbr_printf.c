/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:42:36 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/11/07 12:49:39 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_printf(int n)
{
	int		count;
	char	*num;

	num = ft_itoa(n);
	count = ft_putstr_printf(num);
	free(num);
	return (count);
}
