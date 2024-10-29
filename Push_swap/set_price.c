/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_price.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlos- <scarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:37:41 by scarlos-          #+#    #+#             */
/*   Updated: 2024/10/23 17:43:56 by scarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_price(int position, int len, bool below_median)
{
	if (below_median)
		return (position);
	return (len - position);
}

int	get_push_price(int price_a, int price_b, bool same_side)
{
	if (same_side)
	{
		if (price_a > price_b)
			return (price_a);
		return (price_b);
	}
	return (price_a + price_b);
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	price_a;
	int	price_b;
	int	same_side;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		price_b = get_price(b->current_position, len_b, b->below_median);
		price_a = get_price(b->target_node->current_position, len_a,
				b->target_node->below_median);
		same_side = (b->below_median == b->target_node->below_median);
		b->push_price = get_push_price(price_a, price_b, same_side);
		b = b->next;
	}
}
