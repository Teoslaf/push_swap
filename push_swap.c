/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:51:40 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/23 14:32:52 by ttaneski         ###   ########.fr       */
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
void free_split(char **split)
{
	if (split == NULL)
		return;

	int i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}

	free(split);
}

void simple_sort(t_list *stack);
{
	
}
int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (argc == 1 || (argc == 2 && (!argv[1][0])))
		return 1;
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		createStack(argv, &stack_a);
		print_stack(stack_a);
		free_split(argv);
	}
	else
	{
		createStack(argv + 1, &stack_a);
		print_stack(stack_a);
	}

	deallocate(&stack_a);
	deallocate(&stack_b);

	return 0;
}
