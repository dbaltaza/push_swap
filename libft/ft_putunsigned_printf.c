/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:43:01 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/11/07 12:50:06 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_printf(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned_printf(n / 10);
	count += ft_putchar_printf((n % 10) + '0');
	return (count);
}
