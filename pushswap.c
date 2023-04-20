/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:54:09 by ttaneski          #+#    #+#             */
/*   Updated: 2023/04/20 17:10:33 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int x;
	struct Node* next;	
} Node;

void insert_end(Node **root, int value)
{
	Node* new_node = malloc(sizeof(Node));
	if(new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;

	Node *curr = *root;
	while(curr->next != NULL)
		curr = curr-> next;
	curr->next = new_node;
}
int main(int argc, char **argv)
{
	Node *root = malloc(sizeof(Node));
	if(root == NULL)
	{
		exit(2);
	}
	root->x = 15;
	root->next = NULL;

	insert_end(&root, 10);
	insert_end(&root, 11);
	Node *curr = root;
	while(curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}

	return(0);
}
