/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:57:47 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/23 13:49:02 by ttaneski         ###   ########.fr       */
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
				deallocate(stack_a);
				free_split(argv);
				exit(0);
			}
			j++;
		}
		nbr = atol(arg);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			deallocate(stack_a);
			free_split(argv);
			exit(0);
		}
		if (err_rep(*stack_a, (int)nbr))
		{
			deallocate(stack_a);
			free_split(argv);
			exit(0);
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

void deallocate(t_list **root)
{
	t_list *curr = *root;
	while (curr != NULL)
	{
		t_list *aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}
