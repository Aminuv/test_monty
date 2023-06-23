#include "monty.h"

/**
 * swap - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;

		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		tmp->prev = *stack;
		(*stack)->next = tmp;
		(*stack)->prev = NULL;
	}
}
