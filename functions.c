#include "monty.h"
/**
 * pushStack - function to push a stack
 * @stack: the estructure
 * @line_number: Carries the information of the line number
*/
void pushStack(stack_t **stack, unsigned int line_number)
{
	int n, i;
	stack_t *newnode = NULL;
	char *value = strtok(NULL, " \t\n");

	if (value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; value[i] != '\0'; i++)
	{
		if (!isdigit(value[i]) && value[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(value);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		freestack(newnode);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	newnode->prev = NULL;
	if (!*stack)
		newnode->next = NULL;
	else
	{
		newnode->next = *stack;
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}
/**
 * pallStack - function to print all the stacks
 * @head: the estructure.
 * @line_number: Carries the information of the line number
*/
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
/**
 * freestack - function to free an entire stack
 * @head: pointer to the first stack
*/
void freestack(stack_t *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}
/**
 * freeNode - function to free a node
 * @node: the node to be freed.
*/
void freeNode(stack_t *node)
{
	free(node);
}
/**
 * pintStack - function to print the top stack.
 * @stack: the estructure.
 * @line_number: Carries the information of the line number
*/
void pintStack(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
