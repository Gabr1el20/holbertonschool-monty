#include "monty.h"
/**
 * execute - function to execute the tokenized opcode
 * @opcode: return of get_op
 * @stack: the stack where the function will apply.
 * @line_number: information about the number of lines.
 * Return: 0 on success, 1 otherwise.
*/
int execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t opcodes[] = {
		{"push", pushStack},
		{"pall", pallStack},
		{"pint", pintStack},
		{"pop", popStack},
		{"swap", swapStack},
		{"add", addStack},
		{"nop", nopStack},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return (0);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
