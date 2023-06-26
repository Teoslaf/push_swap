/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:35:16 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/26 14:56:50 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_list *stack)
{
	int	max_value;
	int	max_index;

	max_value = stack->x;
	max_index = stack->index;
	while (stack != NULL)
	{
		if (stack->x > max_value)
		{
			max_value = stack->x;
			max_index = stack->index;
		}
		stack = stack->next;
	}
	return (max_index);
}

int	sorted(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			return (0); // Not sorted
		stack = stack->next;
	}
	return (1); // Sorted
}

void	tiny_sort(t_list **stack)
{
	int max_index;
	
	max_index = get_max_index(*stack);
	if (sorted(*stack) == 1)
		return ;
	if((*stack)->index == max_index)
		ra(stack);
	else if((*stack)->next->index == max_index)
		rra(stack);
	if((*stack)->index > (*stack)->next->index)
		sa(stack);
}
/* tiny_sort:
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/

 