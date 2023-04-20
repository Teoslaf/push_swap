/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:54:09 by ttaneski          #+#    #+#             */
/*   Updated: 2023/04/20 16:39:05 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int x;
	struct Node* next;	
} Node;

int main(int argc, char **argv)
{
	Node root;
	Node elem2; 
	root.x = 15;
	root.next = malloc(sizeof(Node));
	root.next-> x = 2;
	root.next-> next =NULL;

	Node *curr = &root;
	while(curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	printf("first: %d\n", root.x);
	printf("snd: %d\n", root.next->x);

	free(root.next);
	return(0);
}
