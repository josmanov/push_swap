/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:57:11 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/30 17:57:14 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**split_argv;
	bool	is_split;

	a = NULL;
	b = NULL;
	is_split = (argc == 2);
	if (is_split)
	{
		if (argv[1][0] == '\0')
			return (write(2, "Error\n", 6));
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			error_free(&a, argv, is_split);
		stack_init(&a, split_argv, is_split);
	}
	else
		stack_init(&a, argv + 1, is_split);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, false);
		else if (ft_lstsize(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}

