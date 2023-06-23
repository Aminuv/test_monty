#include "monty.h"

/**
 * pchar - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = (*stack)->n;

		if (res < 0 || res > 127)
		{
			fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
			free_args(var.args);
			free_stack(var.stack);
			exit(EXIT_FAILURE);
		}
		fprintf(stdout, "%c\n", res);
	}
}
