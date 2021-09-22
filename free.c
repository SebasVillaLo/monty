#include "monty.h"
/**
 * free_stack - free the stack allocated
 * @status: status exit
 * @arg: arguments
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
/**
 * free_line - Free the line
 * @status: the exit
 * @arg: the line
 */
void free_line(int status, void *arg)
{
	char **line = arg;

	(void)(status);
	if (*line != NULL)
		free(*line);
}
/**
 * f_close - Close the file
 * @status: the exit
 * @arg: the file
 */
void f_close(int status, void *arg)
{
	FILE *file;

	(void)(status);

	file = (FILE *)arg;
	fclose(file);
}
