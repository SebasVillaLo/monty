#include "monty.h"
#include <ctype.h>
/**
 * check_for_digit - checks that a string only contains digits
 * @arg: string to check
 *
 * Return: 0 if only digits, else 1
 */
static int check_for_digit(const char *arg)
{
	int iter;

	for (iter = 0; arg[iter]; iter++)
	{
		if (arg[iter] == '-' && iter == 0)
			continue;
		if (isdigit(arg[iter]) == 0)
			return (1);
	}
	return (0);
}

/**
 * _push - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, " \t\r\n");
	if (arg == NULL || check_for_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
