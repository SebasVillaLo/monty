#include "monty.h"
/**
 * free_stack - free the stack allocated
 * @stack: the stack allocated
 * Return: void
 */
void free_stack(int status, void *arg)
{
	stack_t *next;
	stack_t **stack;

	(void)(status);

	stack = (stack_t **)arg;
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

void free_line(int status, void *arg)
{
	char **line = arg;

	(void)(status);
	if (*line != NULL)
		free(*line);
}

void f_close(int status, void *arg)
{
	FILE *file;

	(void)(status);

	file = (FILE *)arg;
	fclose(file);
}
