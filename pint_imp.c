#include "monty.h"

/**
 * pint - print the value in the up of the stack
 * @stack: stack pointer
 * @line_number: numb of actual line 
 * Return: void
 */

var_t var;

void m_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		fprintf(stderr, "L%d: Can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
