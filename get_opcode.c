#include "monty.h"
char *value;
char *get_op(char *line, unsigned int line_number)
{
    char *opcode = strtok(line, " \n\t");
    value = strtok(NULL, " \n\t");
    (void)line_number;
    if (opcode == NULL || opcode[0] == '#')
        return NULL;
    return opcode;
}