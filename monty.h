#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

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

/**
 * struct global_s - global variable
 * @n: stack input data
 * @line_number: line_number
 *
 * Description: struct holding line_number and stack
 * input data
 */
typedef struct global_s
{
        unsigned int line_number;
        int n;
	char **args;
	stack_t *stack;
	int stack_queue;
} global_t;

extern global_t var;

/**********main.c**********/
void rmv_spaces(char *str);
void prs_input(FILE *fd);
char **pars_args(char *cmd, const char *delim);
void free_args(char **args);
void free_stack(stack_t *stack);

/**********aux.c**********/
char *_str_dup(char *str);
int _atoi(char **num);
void add_dnod_eint(stack_t **stack, int n);
void add_dnod_eint_end(stack_t **stack, int n);

/**********main.c**********/
void rmv_spaces(char *str);
char **pars_args(char *cmd, const char *delim);

/**********instructions.c**********/
void (*instruct(char **s))(stack_t **, unsigned int);

/**********ops1.c**********/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/**********ops2.c**********/
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/**********ops1.c**********/
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif
