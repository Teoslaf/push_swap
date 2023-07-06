/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:57:47 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/04 17:06:00 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deallocate_stack_args(char **argv, t_list **stack_a)
{
	deallocate(stack_a);
	ft_putstr_fd("Error \n", 1);
	free_split(argv);
	exit(0);
}

void	push_to_stack_args(char *arg, t_list **stack_a)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->x = ft_atoi(arg);
	new_node->next = *stack_a;
	new_node->index = 0;
	*stack_a = new_node;
}

void	validate_arguments_args(char *arg, t_list **stack_a, char **argv)
{
	long	nbr;
	int		j;

	j = 0;
	if (arg[j] == '-')
		j++;
	while (arg[j] != '\0')
	{
		nbr = ft_atol(arg);
		if (!ft_isdigit(arg[j]) || (nbr) > INT_MAX || nbr < INT_MIN
			|| err_rep(*stack_a, (int)nbr))
		{
			deallocate_stack_args(argv, stack_a);
			return ;
		}
		j++;
	}
	push_to_stack_args(arg, stack_a);
}

void	create_stack_args(char **argv, t_list **stack_a)
{
	int		i;
	char	*arg;

	i = 0;
	*stack_a = NULL;
	while (argv[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		arg = argv[i];
		validate_arguments_args(arg, stack_a, argv);
	}
	assign_index(*stack_a);
}
