/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:53:18 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/03 17:34:35 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				x;
	int				index;
	struct s_list	*next;

}					t_list;

void				create_stack(char **argv, t_list **stack_a);
void				create_stack_args(char **argv, t_list **stack_a);
int					err_rep(t_list *stack_a, int nbr);
void				deallocate(t_list **root);
void				free_split(char **split);
void				assign_index(t_list *stack_a);
int					ft_list_size(t_list *begin_list);
int					sorted(t_list *stack);
void				tiny_sort(t_list **stack_a, t_list **stack_b);
void				radix_sort(t_list **stack_a, t_list **stack_b);
int					sorted(t_list *stack);
int					get_distance(t_list **stack, int index);
int					get_min(t_list **stack, int val);

void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

#endif
