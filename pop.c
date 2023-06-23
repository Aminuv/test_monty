#include "monty.h"
/**
 * pop - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;

		*stack = (*stack)->next;
		free(tmp);
	}
}
