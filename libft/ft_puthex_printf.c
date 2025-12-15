/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:44:09 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/11/07 12:49:26 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_printf(unsigned int n, char format)
{
	char	*hex_digits;
	int		count;

	count = 0;
	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_printf(n / 16, format);
	count += ft_putchar_printf(hex_digits[n % 16]);
	return (count);
}
