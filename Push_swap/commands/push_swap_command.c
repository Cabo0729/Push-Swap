/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlos- <scarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:57:27 by scarlos-          #+#    #+#             */
/*   Updated: 2024/10/23 17:10:18 by scarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void	rotation(t_stack **stack,
							t_stack *found_node,
							char stack_name)
{
	while (*stack != found_node)
	{
		if (stack_name == 'a')
		{
			if (found_node->below_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (found_node->below_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	set_price(*a, *b);
	set_cheapest(*b);
	cheapest_node = return_cheapest(*b);
	if (cheapest_node->below_median
		&& cheapest_node->target_node->below_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->below_median)
		&& !(cheapest_node->target_node->below_median))
		reverse_rotate_both(a, b, cheapest_node);
	rotation(b, cheapest_node, 'b');
	rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack		*smallest;
	int			len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->below_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
