/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:54:09 by ttaneski          #+#    #+#             */
/*   Updated: 2023/06/23 13:52:22 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int x;
	struct Node *next;
} Node;

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

void sort_first_two(Node **root)
{
	if (*root == NULL || (*root)->next == NULL)
		return; // No need to sort if the list is empty or has only one element

	// Check if the first two elements need to be swapped
	if ((*root)->x > (*root)->next->x)
	{
		// Swap the values of the first two nodes
		int temp = (*root)->x;
		(*root)->x = (*root)->next->x;
		(*root)->next->x = temp;
	}
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
	Node *stack_a = NULL;
	Node *stack_b = NULL;

	insert_beginning(&stack_a, 3);
	insert_beginning(&stack_a, 2);
	insert_beginning(&stack_a, 1);

	insert_beginning(&stack_b, 6);
	insert_beginning(&stack_b, 5);
	insert_beginning(&stack_b, 4);

	push(&stack_a, &stack_b);
	Node *curr_b = stack_b;
	while (curr_b != NULL)
	{
		printf("%d\n", curr_b->x);
		curr_b = curr_b->next;
	}
	printf("+++++++++++++++++++++++++\n");

	Node *curr_a = stack_a;
	while (curr_a != NULL)
	{
		printf("%d\n", curr_a->x);
		curr_a = curr_a->next;
	}
	deallocate(&stack_a);
	deallocate(&stack_b);
	return (0);
}
