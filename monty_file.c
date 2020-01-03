#include "monty.h"

void find(char *path, stack_t **stack)
{
	FILE *file;
	char *command;
	size_t var1;
	unsigned int line_number = 1;
	char *buffer = NULL;

	if (!path)
	{
		fprint(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}

	file = fopen(path, "r");
	if (!file)
	{
		fprint(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &var1, file) != -1)
	{
		command = strtok(buffer, " \n\t\r");
		if (command)
			function_select(&stack, line_number);
		line_number++;
	}
	free(buffer);
	fclose(file);
	exit(EXIT_SUCCESS);
}

void select(stack_t **stack, unsigned int line_number)
{
	instruction_t functions[] = {
		{"pint", pint},
		{"pall", pall},
		{"push", push},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
		{NULL, NULL}
	};

	for (var1 = 0; functions[var1].opcode != NULL; var1++)
	{
		if (strcmp(functions[var1].opcode, command) == 0)
		{
			functions[var1].f(&stack, line_number);
			return;
		}
	}
}
