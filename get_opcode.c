#include "monty.h"

char *get_op(char *line, unsigned int line_number)
{
    char *opcode = NULL;

    (void)line_number;
    opcode = strtok(line, " \t\n");
    value = strtok(NULL, " \t\n");
    if (opcode == NULL || opcode[0] == '#')
        return (NULL);
    return (opcode);
}