#include "monty.h"

/**
 * popStack - function to remove the top stack.
 * @stack: the estructure.
 * @line_number: Carries the information of the line number
*/
void popStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(temp);
}
/**
 * nopStack - N/D
 * @stack: the estructure.
 * @line_number: Carries the information of the line number
*/
void nopStack(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
}
/**
 * swapStack - function to swap the two top stacks.
 * @stack: the estructure.
 * @line_number: Carries the information of the line number
*/
void swapStack(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	int n = head->n;

	head->n = head->next->n;
	head->next->n = n;
}
/**
 * addStack - function to add the n of the two top
 * stacks and remove the toppest one.
 * @stack: the struct
 * @line_number: handler of number of lines.
*/
void addStack(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int n = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = head->n;
	head->next->n += n;
	head->next->prev = NULL;
	*stack = head->next;
	free(head);
}
