/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:42:36 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/11/07 18:43:17 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format_handler(char format, va_list *args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar_printf(va_arg(*args, int));
	else if (format == 's')
		count = ft_putstr_printf(va_arg(*args, char *));
	else if (format == 'p')
		count = ft_putptr_printf(va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr_printf(va_arg(*args, int));
	else if (format == 'u')
		count = ft_putunsigned_printf(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		count = ft_puthex_printf(va_arg(*args, unsigned int), format);
	else if (format == '%')
		count = ft_putchar_printf('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_format_handler(format[i], &args);
		}
		else if (format[i] != '%')
			count += ft_putchar_printf(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
