#include "monty.h"

/**
 * instruct - selects a correct func to perform the operation.
 * @s: operator for pass of the program
 * 
 * Return: appropraite function or NULL if it does not exist.
 */
void (*instruct(char **s))(stack_t **, unsigned int)
{
	int i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	if (!strcmp(s[0], "push"))
		var.n = _atoi(s);

	for (i = 0; ops[i].opcode; i++)
		if (!strcmp(ops[i].opcode, s[0]))
			return (ops[i].f);

	return (NULL);
}
