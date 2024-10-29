/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:35:04 by scarlos-          #+#    #+#             */
/*   Updated: 2024/10/11 21:46:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static t_stack	*find_highest(t_stack *stack)
{
	int			high_value;
	t_stack		*high_node;

	if (stack == NULL)
		return (NULL);
	high_value = INT_MIN;
	while (stack)
	{
		if (stack->value > high_value)
		{
			high_value = stack->value;
			high_node = stack;
		}
		stack = stack->next;
	}
	return (high_node);
}

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		rotation(a, find_smallest(*a), 'a');
		pb(b, a);
	}
}
