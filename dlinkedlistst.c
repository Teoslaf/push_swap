#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int x;
    struct Node *next;
    struct Node *prev;
} Node;

void dealloctate(Node **tail, Node **head)
{
    if (*tail == NULL)
        return;
    Node *curr = *tail;

    while (curr->next != NULL)
    {
        curr = curr->next;
        free(curr->prev);
    }
    free(curr);
    *tail = NULL;
    *head = NULL;
}
void insert_beggining(Node **root, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        exit(1);

    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = *root;
    if (*root != NULL)
        (*root)->prev = new_node;
    *root = new_node;
}
void insert_after(Node *node, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        exit(1);
    new_node->x = value;
    new_node->prev = node;
    new_node->next = node->next;
    if(node->next != NULL)
        node->next->prev = new_node;
    node->next = new_node;
}
void init(Node **tail, Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(2);
        return;
    }
    new_node->x = value;

    new_node->prev = NULL;
    new_node->next = NULL;
    *tail = new_node;
    *head = new_node;
}
void insert_end(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(3);
        return;
    }
    new_node->x = value;
    new_node->next = NULL;
    new_node->prev = *head;
    (*head)->next = new_node;
    *head = new_node;
}
int main(int argc, char **argv)
{
    Node *tail = NULL;
    Node *head = NULL;

    init(&tail, &head, 7);
    insert_beggining(&tail, 3);
    insert_beggining(&tail, 1);
    insert_after(tail->next, 5);

    Node *curr = tail;
    while (curr != NULL)
    {
        printf("%d\n", curr->x);
        curr = curr->next;
    }

    dealloctate(&tail, &head);

    return 0;
}
