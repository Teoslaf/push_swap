/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:51:40 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/07 12:21:31 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
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

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_list_size(*stack_a) <= 5)
		tiny_sort(stack_a, stack_b);
	else 
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && (!argv[1][0])))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		create_stack_args(argv, &stack_a);
		free_split(argv);
	}
	else
		create_stack(argv + 1, &stack_a);
	sort_stack(&stack_a, &stack_b);
	deallocate(&stack_a);
	deallocate(&stack_b);
	return (0);
}
