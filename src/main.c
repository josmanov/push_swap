/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:57:11 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/31 01:17:09 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**split_vector(t_list *a, char **argv, bool is_split, char *str)
{
	char	**split_argv;

	if (!str)
		error_free(&a, argv, is_split);
	split_argv = ft_split(str, ' ');
	if (!split_argv)
		error_free(&a, argv, is_split);
	return (split_argv);
}

static void	choose_algo(t_list *a, t_list *b)
{
	if (ft_lstsize(a) == 2)
		sa(&a, false);
	else if (ft_lstsize(a) == 3)
		tiny_sort(&a);
	else
		push_swap(&a, &b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**split_argv;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!argv[1][0])
		return (write(2, "Error\n", 6), 0);
	if (argc == 2)
	{
		split_argv = split_vector(a, argv, true, argv[1]);
		stack_init(&a, split_argv, true);
	}
	else
		stack_init(&a, argv + 1, false);
	if (!stack_sorted(a))
		choose_algo(a, b);
	free_stack(&a);
	return (0);
}
