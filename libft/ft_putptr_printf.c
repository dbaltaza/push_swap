/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:42:15 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/11/07 12:56:55 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_printf(void *ptr)
{
	unsigned long	addr;
	int				count;

	count = 0;
	addr = (unsigned long)ptr;
	count += ft_putstr_printf("0x");
	count += ft_puthex_long_printf(addr);
	return (count);
}
