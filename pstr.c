#include "monty.h"

/**
 * pstr - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	for (; tmp && tmp->n > 0 && tmp->n <= 127; tmp = tmp->next)
		fprintf(stdout, "%c", tmp->n);
	fprintf(stdout, "\n");
	(void)line_number;
}
