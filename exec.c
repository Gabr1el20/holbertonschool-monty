#include "monty.h"

int execute(char *opcode, stack_t **stack, unsigned int line_number)
{
    instruction_t opcodes[] = {
        {"push", pushStack},
        {"pall", pallStack},
        {NULL, NULL}
    };
    for (int i = 0; opcodes[i].opcode != NULL; i++)
    {
        if (strcmp(opcodes[i].opcode, opcode) == 0)
        {
            opcodes[i].f(stack, line_number);
            return 0;
        }
    }
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    return -1;
}