/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_long_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:43:33 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/11/07 12:49:21 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_long_printf(unsigned long num)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_puthex_long_printf(num / 16);
	count += ft_putchar_printf(hex_digits[num % 16]);
	return (count);
}
