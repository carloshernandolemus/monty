#include "monty.h"

/**
 * queuef- Function to describe a data structure queue
 * @stack: Is the pointer to stack mem address
 * @line_number: Is the current line number
 */
void queuef(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.data_str = 0;
}

/**
 * stackf- Function to describe a data structure stack
 * @stack: Is the pointer to stack mem address
 * @line_number: Is the current line number
 */
void stackf(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.data_str = 1;
}
