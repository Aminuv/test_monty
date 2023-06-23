#include "monty.h"

/**
 * pint - push the  data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout, "%i\n", (*stack)->n);
	}
}
