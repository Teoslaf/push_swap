/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:54:09 by ttaneski          #+#    #+#             */
/*   Updated: 2023/04/20 19:04:00 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int x;
	struct Node *next;
} Node;

void insert_end(Node **root, int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;

	if (*root == NULL)
		*root = new_node;
	Node *curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}
void insert_beginning(Node **root, int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		exit(3);
	new_node->x = value;
	new_node->next = *root;

	*root = new_node;
}

void insert_after(Node *node, int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		exit(3);
	new_node->x = value;
	new_node->next = node->next;
	node->next = new_node;
}
void deallocate(Node **root)
{
	Node *curr = *root;
	while (curr != NULL)
	{
		Node *aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

void insert_sorted(Node **root, int value)
{
	if (*root == NULL || (**root).x >= value)
	{
		insert_beginning(root, value);
		return;
	}
	Node *curr = *root;
	while (curr->next != NULL)
	{
		if (curr->next->x >= value)
			break;
		curr = curr->next;
	}
	insert_after(curr, value);
}

int main(int argc, char **argv)
{
	Node *root = NULL;

	insert_sorted(&root, 4);
	insert_sorted(&root, 2);
	insert_sorted(&root, 9);
	insert_sorted(&root, 1);
	insert_sorted(&root, 3);


	Node *curr = root;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	deallocate(&root);
	return (0);
}
