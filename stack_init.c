/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:57:47 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/03 17:20:58 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_list *stack_a)
{
	t_list	*ptr;
	t_list	*highest;
	int		x;
	int		stack_size;

	stack_size = ft_list_size(stack_a);
	while (--stack_size > 0)
	{
		ptr = stack_a;
		x = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->x == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->x > x && ptr->index == 0)
			{
				x = ptr->x;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
void	create_stack(char **argv, t_list **stack_a)
{
	long	nbr;
	int		i;
	char	*arg;
	int		j;
	t_list	*new_node;

	*stack_a = NULL;
	i = 0;
	while (argv[i] != NULL)
	{
		// Count the number of arguments
		i++;
	}
	while (i > 0)
	{
		i--;
		arg = argv[i];
		j = 0;
		// Check if the argument starts with a minus sign
		if (arg[j] == '-')
			j++;
		while (arg[j] != '\0')
		{
			if (!ft_isdigit(arg[j]))
			{
				deallocate(stack_a);
				exit(0);
			}
			j++;
		}
		nbr = atol(arg);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			deallocate(stack_a);
			exit(0);
		}
		if (err_rep(*stack_a, (int)nbr))
		{
			deallocate(stack_a);
			exit(0);
		}
		new_node = malloc(sizeof(t_list));
		new_node->x = atoi(arg);
		new_node->next = *stack_a;
		*stack_a = new_node;
	}
	assign_index(*stack_a);
}
void	create_stack_args(char **argv, t_list **stack_a)
{
	long	nbr;
	int		i;
	char	*arg;
	int		j;
	t_list	*new_node;

	*stack_a = NULL;
	i = 0;
	while (argv[i] != NULL)
	{
		// Count the number of arguments
		i++;
	}
	while (i > 0)
	{
		i--;
		arg = argv[i];
		j = 0;
		// Check if the argument starts with a minus sign
		if (arg[j] == '-')
			j++;
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
		new_node = malloc(sizeof(t_list));
		new_node->x = atoi(arg);
		new_node->next = *stack_a;
		*stack_a = new_node;
	}
	assign_index(*stack_a);
}

t_list	*find_last(t_list *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
int	err_rep(t_list *stack_a, int nbr)
{
	t_list	*a;

	if (stack_a == NULL)
		return (0);
	a = stack_a;
	while (a)
	{
		if (a->x == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
void deallocate(t_list **root)
{
	t_list	*curr;
	t_list	*aux;

	curr = *root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}
