#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * struct var_s - struct to contain the main variables of the monty interpreter
 * @queue: flag to determine if in stack vs queue mode
 * @stack_len: length of the stack
 */

typedef struct var_s
{
	int queue;
	size_t stack_len;
} var_t;

/* global struct to hold flag for queue an stack length */
extern var_t var;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* opcode functions */
char *get_op(char *line, unsigned int line_number);
int execute(char *opcode, stack_t **stack, unsigned int line_number);


/* Stack functions */
void pushStack(stack_t **stack, unsigned int line_number);
void pallStack(stack_t **stack, unsigned int line_number);
void pintStack(stack_t **stack, unsigned int line_number);
void popStack(stack_t **stack, unsigned int line_number);
void swapStack(stack_t **stack, unsigned int line_number);
void addStack(stack_t **stack, unsigned int line_number);
void nopStack(stack_t **stack, unsigned int line_number);


void freestack(stack_t *head);
void freeNode(stack_t *node);


extern char *value;



#endif
