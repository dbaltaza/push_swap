/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:25:52 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:52 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	count_total_args(int argc, char **argv)
{
	int	total;
	int	i;

	total = 0;
	i = 1;
	while (i < argc)
	{
		total += count_words(argv[i], ' ');
		i++;
	}
	return (total);
}

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	process_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit(a, b);
		parse_split(split, a, b);
		free_split(split);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total;

	if (argc < 2)
		return (0);
	total = count_total_args(argc, argv);
	if (total == 0)
		return (0);
	a = init_stack(total);
	b = init_stack(total);
	if (!a || !b)
		return (1);
	process_args(argc, argv, a, b);
	if (!is_sorted(a))
	{
		normalize_stack(a);
		sort_stack(a, b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
