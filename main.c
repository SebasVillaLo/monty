#include "monty.h"
/* global struct to hold flag for queue and stack length */
var_t var;
/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *files = NULL;
	char *line = NULL, *token = NULL;
	size_t line_len = 0;
	unsigned int line_num = 0;

	var.stack_len = 0;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	files = fopen(argv[1], "r");
	if (files == NULL)
		exit(EXIT_FAILURE);

	on_exit(free_stack, &stack);
	on_exit(f_close, files);
	on_exit(free_line, &line);
	while (getline(&line, &line_len, files) != -1)
	{
		line_num++;
		token = strtok(line, "\n\t\r ");
		if (token != NULL && token[0] != '#')
			get_funs(token, &stack, line_num);
	}
	exit(EXIT_SUCCESS);
}
