#include "monty.h"

/**
 * add - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;
		int res;

		res = (*stack)->n + (*stack)->next->n;
		*stack = (*stack)->next;
		(*stack)->n = res;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
