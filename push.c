#include "monty.h"
/**
 * _push - add node to the stack allocated
 * @stack: ...
 * @line_number: ...
 */
void _push(stack_t **stack, unsigned int line_number)
{
	var_t var;
	char *arg;
	int n;

	arg = strtok(NULL, " \t\r\n");
	if (arg == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
