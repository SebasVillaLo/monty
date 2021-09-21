#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;
	
	arg = strtok(NULL, " \t\r\n");
	//printf("%s\n", arg);
	if (arg == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
	printf(">>>%ld\n", var.stack_len);
}