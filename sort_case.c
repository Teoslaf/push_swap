/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:41:08 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/04 14:18:38 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_case_1(t_list **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

static void	sort_case_2(t_list **stack_a, int min)
{
	if ((*stack_a)->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

static void	sort_case_3(t_list **stack_a, int min)
{
	if ((*stack_a)->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_three(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (sorted(*stack_a) == 1)
		return ;
	if (head->index == min && head->next->index != next_min)
		sort_case_1(stack_a);
	else if (head->index == next_min)
		sort_case_2(stack_a, min);
	else
		sort_case_3(stack_a, min);
}
