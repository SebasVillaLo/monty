#include "monty.h"
/**
 * free_stack - free the stack allocated
 * @stack: the stack allocated
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *next;

	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.stack_len = 0;
}
