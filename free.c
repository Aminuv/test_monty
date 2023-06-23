#include "monty.h"

/**
 * free_args - frees the 2 dimensional allocated of the memories
 * @args: the args input
 */
void free_args(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}

/**
 * free_stack - for frees the stack.
 * @stack: pointer to the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp = NULL;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
