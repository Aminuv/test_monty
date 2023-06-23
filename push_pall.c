#include "monty.h"

/**
 * push - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (var.stack_queue == 0)
		add_dnod_eint(stack, var.n);
	else
		add_dnod_eint_end(stack, var.n);

	(void)line_number;
}

/**
 * pall - push the data in the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	for (; tmp; tmp = tmp->next)
		fprintf(stdout, "%i\n", tmp->n);
	(void)line_number;
}
