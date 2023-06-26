/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:51:40 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/26 14:41:23 by ttaneski         ###   ########.fr       */
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

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

void print_stack_with_indices(t_list *stack)
{
	t_list *ptr = stack;

	printf("Stack with indices:\n");
	while (ptr != NULL)
	{
		printf("Value: %d, Index: %d\n", ptr->x, ptr->index);
		ptr = ptr->next;
	}
	printf("\n");
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
		createStack_args(argv, &stack_a);
		print_stack_with_indices(stack_a);
		printf("max index:%d", get_max_index(stack_a));
		free_split(argv);
	}
	else
	{
		createStack(argv + 1, &stack_a);
		print_stack_with_indices(stack_a);
		printf("max index:%d \n", get_max_index(stack_a));
	}
	tiny_sort(&stack_a);
	print_stack_with_indices(stack_a);
	deallocate(&stack_a);
	deallocate(&stack_b);

	return 0;
}

