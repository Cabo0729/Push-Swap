/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:18:52 by scarlos-          #+#    #+#             */
/*   Updated: 2024/10/11 20:51:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

//check syntax.overflow.doble
void	fill_stack(t_stack **a, char **av, bool av_true)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, av_true);
		nbr = ft_atoi(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, av_true);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, av_true);
		add_node(a, (int)nbr);
		i++;
	}
	if (av_true)
		free_str(av);
}
