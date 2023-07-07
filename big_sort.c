/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:47:01 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/07 12:42:28 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_pass(t_list **stack_a, t_list **stack_b, int bit_index)
{
	t_list	*head_a;
	int		size;
	int		j;

	head_a = *stack_a;
	size = ft_list_size(head_a);
	j = 0;
	while (j < size)
	{
		head_a = *stack_a;
		if (((head_a->index >> bit_index) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		j++;
	}
	while (ft_list_size(*stack_b) != 0)
		pa(stack_b, stack_a);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	i;

	max_bits = get_max_bits(stack_a);
	if (sorted(*stack_a) == 1)
		return ;
	i = 0;
	while (i < max_bits)
	{
		radix_pass(stack_a, stack_b, i);
		i++;
	}
}
