/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:57:47 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/19 15:27:00 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void createStack(char **argv, t_list **stack_a)
{
	*stack_a = NULL;
	long nbr;
	int i = 0;

	while (argv[i] != NULL)
	{
		char *arg = argv[i];
		int j = 0;

		while (arg[j] != '\0')
		{
			if (!ft_isdigit(arg[j]))
			{
				printf("Invalid input: '%s' is not a valid number.\n", arg);
				exit(1);
			}
			j++;
		}
		nbr = atol(arg);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			printf("Number out of range: '%ld' is not within the valid range.\n", nbr);
			exit(1);
		}
		if (err_rep(*stack_a, (int)nbr))
		{
			printf("Duplicate number: '%ld' already exists in the stack.\n", nbr);
			exit(1);
		}
		t_list *new_node = malloc(sizeof(t_list));
		new_node->x = atoi(arg);
		new_node->next = *stack_a;
		*stack_a = new_node;
		i++;
	}
}
t_list *find_last(t_list *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
int err_rep(t_list *stack_a, int nbr)
{
	if (stack_a == NULL)
		return 0;

	t_list *a = stack_a;
	while (a)
	{
		if (a->x == nbr)
			return 1;
		a = a->next;
	}
	return 0;
}

// void append_node(t_list **stack, int nbr)
// {
// 	t_list *node;
// 	t_list *last_node;
// 	if (NULL == stack)
// 		return;
// 	node = malloc(sizeof(t_list));
// 	if (NULL == node)
// 		return;
// 	node->next = NULL;
// 	node->x = nbr;
// 	if (*stack == NULL)
// 	{
// 		*stack = node;
// 		node->prev = NULL;
// 	}
// 	else
// 	{
// 		last_node = find_last(*stack);
// 		last_node->next = node;
// 		node->prev = last_node;
// 	}
// }

void deallocate(t_list **stack)
{
	t_list *curr = *stack;
	while (curr != NULL)
	{
		t_list *aux = curr;
		curr = curr->next;
		free(aux);
	}
	*stack = NULL;
}