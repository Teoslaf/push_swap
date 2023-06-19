/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:51:40 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/17 16:34:35 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_list *stack)
{
	t_list *curr = stack;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
}

int main(int argc, char **argv)
{
	t_list **stack_a;
	t_list **stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = (t_list **)malloc(sizeof(t_list *));


	if (argc == 1 || (argc == 2 && (!argv[1][0])))
		return 1;
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		createStack(argv, stack_a);
		print_stack(*stack_a);
	}
	else 
	{
		createStack(argv + 1, stack_a);
		print_stack(*stack_a);
	} 
	stack_b = (t_list **)malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	// deallocate(stack_a);
	return 0;
}
