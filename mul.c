#include "monty.h"

/**
 * mul - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;
		int res;

		res = (*stack)->next->n * (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->n = res;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
