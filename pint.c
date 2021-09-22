#include "monty.h"
/**
 * _pint - print the information for node
 * @stack: ...
 * @line_number: ...
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0 || !stack || !*stack)
	{
		dprintf(STDOUT_FILENO,"L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}
