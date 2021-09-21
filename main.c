#include "monty.h"
/**
 * main - main program
 * @argc: ...
 * @argv: ...
 * @int: ...
 * 
 * Return: EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *files = NULL;
	char *line = NULL, *token = NULL;
	unsigned int line_num = 0;
	size_t line_len = 0;

	var.queue = 0;
	var.stack_len = 0;
	if (argc != 2)
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	files = fopen(argv[1], "r");
	if (files == NULL)
		exit(EXIT_FAILURE);

	on_exit(free_lineptr, &line);

	while (getline(&line, &line_len, files) != -1)
	{
		line_num++;
		token = strtok(line, "\n\t\r ");
		if (token != NULL && token[0] != '#')
			get_funs(token, &stack, line_num);
	}
	fclose(files);
	exit(EXIT_SUCCESS);
}
