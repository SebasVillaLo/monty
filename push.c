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
	stack_t *new_node;
	char *arg;

	arg = strtok(NULL, " \n\t\r");
	if (arg == NULL || integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	if (*stack == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*stack)->prev->next = new_node;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	*stack = new_node;
	var.stack_len++;
}