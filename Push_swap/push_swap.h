/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:03:02 by scarlos-          #+#    #+#             */
/*   Updated: 2024/10/07 20:35:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int					value;
	int					current_position;
	int					push_price;
	bool				below_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;

char			**ft_split(char *str, char c);

//cheack-errors-free
void			free_str(char **argv);
void			error_free(t_stack **a, char **av, bool av_true);
void			free_stack(t_stack **stack);
int				error_repetition(t_stack *a, int nbr);
int				error_syntax(char *str_nbr);

//create stack
void			fill_stack(t_stack **a, char **av, bool av_true);
void			init_nodes(t_stack *a, t_stack *b);
void			set_current_position(t_stack *stack);
void			set_price(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);

//linked list
void			add_node(t_stack **stack, int nbr);
t_stack			*find_last_node(t_stack *head);
t_stack			*find_smallest(t_stack *stack);
t_stack			*return_cheapest(t_stack *stack);
int				stack_sorted(t_stack *stack);
int				stack_len(t_stack *stack);
void			rotation(t_stack **s, t_stack *n, char c);

//algorithms
void			tiny_sort(t_stack **a);
void			handle_five(t_stack **a, t_stack **b);
void			push_swap(t_stack **a, t_stack **b);

//commands
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);

#endif
