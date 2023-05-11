#include "monty.h"
char *value;
void pushStack(stack_t **head, unsigned int line_number)
{
    if (value == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    int n = atoi(value);
    stack_t *newnode = malloc(sizeof(stack_t));
    if (newnode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    newnode->n = n;
    newnode->prev = NULL;
    if (!*head)
        newnode->next = NULL;
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
    }
    *head = newnode;
}

void pallStack(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    (void)line_number;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void freestack(stack_t *head)
{
    while (head)
    {
        free(head);
        head = head->next;
    }
}