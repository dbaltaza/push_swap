/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:30:00 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:36 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(long num, int digit, int sign)
{
	if (sign == 1 && (num > INT_MAX / 10
			|| (num == INT_MAX / 10 && digit > INT_MAX % 10)))
		return (1);
	if (sign == -1 && (num > -(long)INT_MIN / 10
			|| (num == -(long)INT_MIN / 10 && digit > -(INT_MIN % 10))))
		return (1);
	return (0);
}

static int	parse_digits(const char *str, int i, int sign, long *result)
{
	long	num;

	num = 0;
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(num, str[i] - '0', sign))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*result = num * sign;
	return (1);
}

static int	ft_atol_check(const char *str, long *result)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (parse_digits(str, i, sign, result));
}

static int	has_duplicate(t_stack *a, int num)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	parse_split(char **split, t_stack *a, t_stack *b)
{
	int		i;
	long	num;

	i = 0;
	while (split[i])
	{
		if (!ft_atol_check(split[i], &num))
			error_exit(a, b);
		if (has_duplicate(a, (int)num))
			error_exit(a, b);
		a->array[a->size] = (int)num;
		a->size++;
		i++;
	}
}
