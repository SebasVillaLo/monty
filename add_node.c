#include "monty.h"
/**
 * add_node - add a node to the stack allocated
 * @n: ...
 * @stack: ...
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *NewNode;

	if (stack == NULL)
		return (NULL);

	NewNode = malloc(sizeof(stack_t));
	if (NewNode == NULL)
		return (NULL);

	NewNode->n = n;
	if (*stack == NULL)
	{
		NewNode->prev = NewNode;
		NewNode->next = NewNode;
	}
	else
	{
		(*stack)->prev->next = NewNode;
		NewNode->prev = (*stack)->prev;
		(*stack)->prev = NewNode;
		NewNode->next = *stack;
	}
	*stack = NewNode;
	return (NewNode);
}
