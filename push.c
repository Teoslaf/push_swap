/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:44:13 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/21 15:52:52 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **source, t_list **destination)
{
	if (*source == NULL)
		return; // No element to push

	t_list *top = *source;	   // Get the top element from source stack
	*source = (*source)->next; // Update source stack

	top->next = *destination; // Push the element to the destination stack
	*destination = top;
}

void pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}
void pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}