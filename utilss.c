/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:50:34 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/04 14:18:31 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

t_list	*find_highest(t_list *stack_a)
{
	t_list	*ptr;
	int		x;
	t_list	*highest;

	ptr = stack_a;
	x = INT_MIN;
	highest = NULL;
	while (ptr)
	{
		if (ptr->x == INT_MIN && ptr->index == 0)
			ptr->index = 1;
		if (ptr->x > x && ptr->index == 0)
		{
			x = ptr->x;
			highest = ptr;
			ptr = stack_a;
		}
		else
			ptr = ptr->next;
	}
	return (highest);
}

void	assign_index(t_list *stack_a)
{
	int		stack_size;
	t_list	*highest;

	stack_size = ft_list_size(stack_a);
	while (--stack_size > 0)
	{
		highest = find_highest(stack_a);
		if (highest != NULL)
			highest->index = stack_size;
	}
}
