#include "monty.h"
/**
 * _str_dup - returns a pointer to a newly allocated space in memory.
 * @str: input string
 * 
 * Return: array of pointer
 */
char *_str_dup(char *str)
{
	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		int i = 0, j;
		char *ptr;

		while (*(str + i))
			i++;

		ptr = (char *)malloc(sizeof(char) * i + 1);
		if (ptr == NULL)
			return (NULL);

		for (j = 0; j < i; j++)
			*(ptr + j) = *(str + j);

		ptr[i] = '\0';

		return (ptr);
	}
}

/**
 * _atoi - to converts a string to integer
 * @str: input of string
 *
 * Return: converte str
 */
int _atoi(char **str)
{
	int num = 0;
	int sign = 1;
	int i = 0;

	if (!(str[1]) || !(*(str[1])))
	{
		fprintf(stderr, "L%i: usage: push integer\n", var.line_number);
		free_args(str);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}

	if (str[1][i] == '-' || str[1][i] == '+')
	{
		sign = (str[1][i] == '-') ? -1 : 1;
		i++;
	}

	for (; str[1][i]; i++)
	{
		if (!(str[1][i] >= '0' && str[1][i] <= '9'))
		{
			fprintf(stderr, "L%i: usage: push integer\n", var.line_number);
			free_args(str);
			free_stack(var.stack);
			exit(EXIT_FAILURE);
		}
		num = (num * 10) + (str[1][i] - '0');
	}

	return (num * sign);
}

/**
 * add_dnod_eint - adding a new value to the top of the stack.
 * @stack: pointer to the stack
 * @n: value of stack
 */
void add_dnod_eint(stack_t **stack, int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(*new));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * add_dnod_eint_end - adding a new value at the end of a queue.
 * @stack: pointer to the queue
 * @n: value of queue
 */
void add_dnod_eint_end(stack_t **stack, int n)
{
	stack_t *new = NULL;
	stack_t *tmp = *stack;

	new = malloc(sizeof(*new));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (!(*stack))
	{
		new->next = *stack;
		*stack = new;

		return;
	}

	for (; tmp->next; tmp = tmp->next)
		;

	tmp->next = new;
	new->prev = tmp;
}
