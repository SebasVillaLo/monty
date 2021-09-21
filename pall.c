#include "monty.h"
/**
 * _pall - Print nodes
 *
 * @stack: ...
 * @line_number: ...
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
			return;
	}
}
