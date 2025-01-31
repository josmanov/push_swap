/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:35:35 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/31 08:31:40 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				current_position;
	int				final_index;
	int				push_price;
	int				above_median;
	char			*str_buf;
	void			*content;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

void	free_matrix(char **argv);
void	error_free(t_list **a, char **argv, bool is_split);
void	free_stack(t_list **stack);
int		error_repetition(t_list *a, int nbr);
int		error_syntax(char *str);

void	stack_init(t_list **a, char **argv, bool is_split);
void	init_nodes(t_list *a, t_list *b);
void	set_current_position(t_list *stack);
void	set_price(t_list *a, t_list *b);
void	set_cheapest(t_list *b);

void	append_node(t_list **stack, int nbr);
t_list	*find_last_node(t_list *head);
t_list	*find_smallest(t_list *stack);
t_list	*return_cheapest(t_list *stack);
bool	stack_sorted(t_list *stack);
int		stack_len(t_list *stack);
void	finish_rot(t_list **s, t_list *n, char c);

void	tiny_sort(t_list **a);
void	handle_five(t_list **a, t_list **b);
void	push_swap(t_list **a, t_list **b);

void	sa(t_list **a, bool checker);
void	sb(t_list **b, bool checker);
void	ss(t_list **a, t_list **b, bool checker);
void	ra(t_list **a, bool checker);
void	rb(t_list **b, bool checker);
void	rr(t_list **a, t_list **b, bool checker);
void	rra(t_list **a, bool checker);
void	rrb(t_list **b, bool checker);
void	rrr(t_list **a, t_list **b, bool checker);
void	pa(t_list **a, t_list **b, bool checker);
void	pb(t_list **b, t_list **a, bool checker);

// Node functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
