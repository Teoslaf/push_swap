/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:29:55 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/21 16:27:20 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1
void rotate(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return; // No need to shift if the stack is empty or has only one element

	t_list *last = *stack;
	while (last->next != NULL)
		last = last->next; // Find the last t_list

	t_list *first = *stack;	 // Get the first node
	*stack = (*stack)->next; // Update the stack to remove the first node
	last->next = first;		 // Make the first node the last node
	first->next = NULL;		 // Set the next of the new last node to NULL
}

void ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);

}