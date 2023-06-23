/**
 * rotl - push the data in the stack or queue
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		return;
	}
	else
	{
		stack_t *tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		add_dnod_eint_end(stack, tmp->n);
		free(tmp);
	}
	(void)line_number;
}
