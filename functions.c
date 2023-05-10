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
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->prev = NULL;
    if (*head == NULL)
        new_node->next = NULL;
    else
    {
        new_node->next = *head;
        (*head)->prev = new_node;
    }
    *head = new_node;
}
void pallStack(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    (void)line_number;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}