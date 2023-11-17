#define _GNU_SOURCE
#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		execute_opcode(&stack, line, line_number);
	}

	fclose(file);

	free_stack(&stack);
	free(line);

	return (EXIT_SUCCESS);
}
