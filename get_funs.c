#include "monty.h"

void get_funs(char *token, stack_t **stack, unsigned int line_number)
{
	unsigned int iter;
	instruction_t validation[] = {
		{"push", _push},
		{"pop", _pop},
		{"pall" , _pall},
		{"pint", _pint},
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
	exit (EXIT_FAILURE);
}