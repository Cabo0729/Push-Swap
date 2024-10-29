/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:26:08 by scarlos-          #+#    #+#             */
/*   Updated: 2024/10/11 21:34:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **av)
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (stack == NULL)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack **a, char **av, bool av_true)
{
	free_stack(a);
	if (av_true)
		free_str(av);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str)
{
	if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
			|| *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (nbr == a->value)
			return (1);
		a = a->next;
	}
	return (0);
}
