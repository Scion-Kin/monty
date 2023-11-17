#include "monty.h"
#include <ctype.h>

/**
 * execute_opcode - executes a line of an opcode
 * @stack: the linked list
 * @line: the line command
 * @line_number: the line number
 * Return: Nothing
 */

void execute_opcode(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode = strtok(line, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
}

/**
 * free_stack - frees memory
 * @stack: linked list
 * Return: Nothing
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

/**
 * is_numeric - checks to see if argument is a number
 * @str: the argument
 * Return: 1 or 0
 */

int is_numeric(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && str[i] != '-')
		{
			return (0);
		}
	}
	return (1);
}
