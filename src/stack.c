/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:57:31 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/31 00:25:03 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	check_overflow(long nbr, char c, int is_neg)
{
	if (is_neg)
		if (nbr > (LONG_MAX - (c - '0')) / 10)
			return (1);
	if (!is_neg)
		if (nbr < (LONG_MIN - (c - '0')) / 10)
			return (1);
	return (0);
}

static int	is_delim(const char c)
{
	if ((c == ' ' || c == '\t'
			|| c == '\n' || c == '\r'
			|| c == '\v' || c == '\f'))
		return (1);
	return (0);
}

long	str_to_long(const char *str, int *is_overflow)
{
	long	nbr;
	int		is_neg;
	int		i;

	nbr = 0;
	is_neg = 1;
	i = 0;
	while (str[i] && is_delim(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(nbr, str[i], is_neg))
			return ((*is_overflow = 1), 0);
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	*is_overflow = 0;
	return (nbr * is_neg);
}

void	stack_init(t_list **a, char **argv, bool is_split)
{
	long	nbr;
	int		i;
	int		is_overflow;

	i = 0;
	is_overflow = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, is_split);
		nbr = str_to_long(argv[i], &is_overflow);
		if (nbr > INT_MAX || nbr < INT_MIN || is_overflow)
			error_free(a, argv, is_split);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, is_split);
		append_node(a, (int)nbr);
		++i;
	}
	if (is_split)
		free_matrix(argv);
}
