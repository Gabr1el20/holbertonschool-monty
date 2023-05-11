#include "monty.h"
/**
 * get_op - function to get the opcode of the file readed.
 * @line: information of the opcode from the file.
 * @line_number: information about the number of lines.
 * Return: the opcode on succes, NULL if the opcode doesn´t exist
 * or if it is a command.
*/
char *get_op(char *line, unsigned int line_number)
{
	char *opcode = NULL;

	(void)line_number;
	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return (NULL);
	return (opcode);
}
