/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:53:18 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/23 14:30:43 by ttaneski         ###   ########.fr       */
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
void	printerror(char *str);
int		err_rep(t_list *stack_a, int nbr);
void 	sa(t_list **stack_a);
void 	pa(t_list **stack_a, t_list **stack_b);
void 	ra(t_list **stack_a);
void 	rra(t_list **stack_a);
void 	rr(t_list **stack_a, t_list **stack_b);
void 	deallocate(t_list **root);
void free_split(char **split);

# endif
