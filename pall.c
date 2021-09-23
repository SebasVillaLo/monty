#include "monty.h"
/**
 * _pall - print all values on `stack' starting from the top
 * @stack: double pointer to head of stack
 * @line_number: line number being executed from script file
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void)(line_number);

	while (head != NULL)
	{
		fprintf(stdout, "%d\n", head->n);
		head = head->next;
		if (head == *stack)
			return;
	}
}
