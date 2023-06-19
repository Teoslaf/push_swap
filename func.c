/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:02:39 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/17 16:21:25 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a and b;
void sa(t_list **root)
{
	if (*root == NULL || (*root)->next == NULL)
		return; // No need to sort if the list is empty or has only one element

	// Check if the first two elements need to be swapped
	if ((*root)->x > (*root)->next->x)
	{
		// Swap the values of the first two nodes
		int temp = (*root)->x;
		(*root)->x = (*root)->next->x;
		(*root)->next->x = temp;
	}
}
// take the first element at the top of b and put it at the top of a
void push(t_list **source, t_list **destination)
{
	if (*source == NULL)
		return; // No element to push

	t_list *top = *source;	   // Get the top element from source stack
	*source = (*source)->next; // Update source stack

	top->next = *destination; // Push the element to the destination stack
	*destination = top;
}

// Shift up all elements of stack a by 1
void shiftUp(t_list **stack)
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
void shiftDown(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return; // No need to shift if the stack is empty or has only one element

	t_list *last = *stack;
	while (last->next != NULL)
		last = last->next; // Find the last node

	last->next = *stack;	 // Make the last node point to the current first node
	*stack = (*stack)->next; // Update the stack to remove the first node
	last->next->next = NULL; // Set the next of the new last node to NULL
}
