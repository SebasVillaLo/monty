#include "monty.h"
/**
 * get_funs - Get the funs object
 * @token: ...
 * @stack: ...
 * @line_number: ...
 */
void get_funs(char *token, stack_t **stack, unsigned int line_number)
{
	unsigned int iter;
	instruction_t validation[] = {
		{"push", _push},
		{"pop", _pop},
		{"pall", _pall},
		{"pint", _pint},
		{"swap", n_swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	for (iter = 0; validation[iter].opcode != NULL; iter++)
	{
		if (strcmp(validation[iter].opcode, token) == 0)
		{
			validation[iter].f(stack, line_number);
			return;
		}
	}
	dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}
