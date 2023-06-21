/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:25:23 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/21 15:40:29 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list *root)
{
	if (root == NULL || root->next == NULL)
		return;

	if (root->x > root->next->x)
	{
		int temp = root->x;
		root->x = root->next->x;
		root->next->x = temp;
	}
}

void sa(t_list **stack_a)
{
	swap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_putstr_fd("sb\n", 1);

}

void ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}
