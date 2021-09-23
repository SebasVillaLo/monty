#include "monty.h"
/**
 * n_swap - swap top two elements of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void n_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *swap_n;

	if (var.stack_len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}

	swap_n = (*stack)->next;
	swap_n->prev = (*stack)->prev;
	(*stack)->prev->next = swap_n;
	(*stack)->prev = swap_n;
	(*stack)->next = swap_n->next;
	swap_n->next->prev = *stack;
	swap_n->next = *stack;
	*stack = swap_n;
}
