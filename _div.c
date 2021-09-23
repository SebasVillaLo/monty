#include "monty.h"

/**
 * m_div - divide second element of stack by top element
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	if (var.stack_len < 2)
	{
		fprintf(stderr,
			"L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	_pop(stack, line_number);
	if (n == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= n;
}