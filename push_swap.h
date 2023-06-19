/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:53:18 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/17 16:33:41 by ttaneski         ###   ########.fr       */
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
	struct s_list *next;
	struct s_list *prev;

} t_list;

void	createStack(char **argv, t_list **stack_a);
void	printerror(char *str);
int		err_rep(t_list *stack_a, int nbr);
void deallocate(t_list **stack);

# endif