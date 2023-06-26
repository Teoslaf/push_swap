/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:53:18 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/26 14:17:21 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h> 
#include "libft/libft.h"

typedef struct s_list
{
	int x;
	int index;
	struct s_list *next;

} t_list;

void	createStack(char **argv, t_list **stack_a);
void 	createStack_args(char **argv, t_list **stack_a);
int		err_rep(t_list *stack_a, int nbr);
void 	sa(t_list **stack_a);
void 	pa(t_list **stack_a, t_list **stack_b);
void 	ra(t_list **stack_a);
void 	rra(t_list **stack_a);
void 	rr(t_list **stack_a, t_list **stack_b);
void 	deallocate(t_list **root);
void 	free_split(char **split);
void 	assign_index(t_list *stack_a);
int	 	ft_list_size(t_list *begin_list);
int		get_max_index(t_list *stack);
int 	sorted(t_list *stack);
void 	tiny_sort(t_list **stack);


# endif
