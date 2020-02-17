#include "monty.h"
global_t global;

/**
 * main - Is the main function
 * @argc:Is the index of argv
 * @argv:Is the array of arguments passed by
 * Return: 0 if is success
 */

int main(int argc, char **argv)
{
	FILE *file_handle;
	char *line_inf;
	size_t size = 0;
	ssize_t line_content = 1;
	stack_t *stack = NULL;
	unsigned int lnum = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_handle = fopen(argv[1], "r");
	global.f_hand = file_handle;

	if (file_handle == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (line_content > 0)
	{
		line_inf = NULL;
		line_content = getline(&line_inf, &size, file_handle);
		global.monty_line = line_inf;
		lnum++;

		if (line_content > 0)
		{
			opcSelec(line_inf, &stack, lnum, file_handle);
		}
		free(line_inf);
	}
	freePlates(stack);
	fclose(file_handle);

	return (0);
}


/**
 * freePlates - Release the mem use of the stack elem
 * @stack: Pointer to stack mem address
 */
void freePlates(stack_t *stack)
{
	stack_t *plate = stack;

	while (stack)
	{
		plate = stack->next;
		free(stack);
		stack = plate;
	}
}


/**
 * opcSelec - Selector of functions
 * @line_inf: Is the words in the line
 * @stck: Pointer to the stack mem add
 * @lnum: current liner number
 * @f_handle: Is the monty file
 * Return: 0 if is compared opcode is found 1 is not
 */
int opcSelec(char *line_inf, stack_t **stck, unsigned int lnum, FILE *f_handle)
{
	unsigned int ind = 0;
	char *codeOp;

	instruction_t listOpc[] = {
		{"push", push_data}, {"pall", print_stack}, {"pint", print_top},
		{"pop", delete_top}, {"swap", swap2top}, {"nop", nop},
		{"add", addm}, {"sub", subm}, {"div", divm}, {"mul", mulm},
		{"mod", modm}, {"pchar", printTopC}, {"pstr", printTopS},
		{"rotl", rotate_top}, {"rotr", rotate_bottom},
		{"queue", queuef}, {"stack", stackf}, {NULL, NULL}
	};

	codeOp = strtok(line_inf, " \n\t");

	if (codeOp && codeOp[0] == '#')
		return (0);

	global.p_data = strtok(NULL, " \n\t");

	while (listOpc[ind].opcode && codeOp)
	{
		if (strcmp(codeOp, listOpc[ind].opcode) == 0)
		{
			listOpc[ind].f(stck, lnum);
			return (0);
		}
		ind++;
	}
	if (codeOp && listOpc[ind].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lnum, codeOp);
		fclose(f_handle);
		free(line_inf);
		freePlates(*stck);
		exit(EXIT_FAILURE);
	}
	return (1);

}
