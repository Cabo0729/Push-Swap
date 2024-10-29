/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlos- <scarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:01:52 by scarlos-          #+#    #+#             */
/*   Updated: 2024/10/23 17:36:57 by scarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (stack == NULL)
		return ;
	mid = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= mid)
			stack->below_median = true;
		else
			stack->below_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_node(t_stack *a,
							t_stack *b)
{
	t_stack		*current_a;
	t_stack		*target_node;
	long		best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long		best_match_value;
	t_stack		*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	best_match_node = NULL;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	if (best_match_node)
		best_match_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
