/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:57:09 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/30 23:44:29 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_matrix(char **argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_list **a, char **argv, bool is_split)
{
	free_stack(a);
	if (is_split)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(2);
}

int	error_syntax(char *str)
{
	if (!str || !*str)
		return (1);
	if (*str == '+' || *str == '-')
	{
		if (!(str[1] >= '0' && str[1] <= '9'))
			return (1);
	}
	else if (!(*str >= '0' && *str <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_list *a, int nbr)
{
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
