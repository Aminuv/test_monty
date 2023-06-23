#include "monty.h"

/**
 * rotr - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		return;
	}
	else
	{
		stack_t *tmp1, *tmp2;

		tmp1 = *stack;
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		add_dnod_eint(stack, tmp2->n);
		free(tmp2);
	}
	(void)line_number;
}
