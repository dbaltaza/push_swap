/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:41:23 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/11/07 18:40:02 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_printf(char *s)
{
	if (s)
		return (write(1, s, ft_strlen(s)));
	return (write(1, "(null)", 6));
}
