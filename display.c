#include "monty.h"

/**
 * print_stack - Print the stack like pall function
 * @stack: Pointer to the mem direction of stack
 * @line_number: Number of actual line
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *show_node = NULL;

	(void)line_number;

	if (!(stack == NULL || *stack == NULL))
	{
		show_node = *stack;
		while (show_node)
		{
			printf("%d\n", show_node->n);
			show_node = show_node->next;
		}
	}
}


/**
 * print_top - print the top element (pint)
 * @stack: Pointer to the mem direction of stack
 * @line_number: Number of actual line
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	int top_plate = 0;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}

	top_plate = (*stack)->n;
	printf("%d\n", top_plate);
}


/**
 * printTopC - Print the top char (pchar)
 * @stack: Pointer to the stack mem address
 * @line_number: Is the current line number
 */
void printTopC(stack_t **stack, unsigned int line_number)
{
	stack_t *c_node = *stack;

	if (c_node == NULL)
	{
		fprintf(stderr, "L%d can't pchar, stack empty\n", line_number);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	if (c_node->n > 127 || c_node->n < 0)
	{
		fprintf(stderr, "L%d can't pchar, stack empty\n", line_number);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c_node->n);
}

/**
 * printTopS -Print the top string (pstr)
 * @stack: Pointer to the stack mem address
 * @line_number: Is the current line number
 */
void printTopS(stack_t **stack, unsigned int line_number)
{
	stack_t *s_node = *stack;
	(void)line_number;

	while (s_node != NULL)
	{
		if (s_node->n <= 0 || s_node->n > 127)
			break;

		printf("%c", s_node->n);
		s_node = s_node->next;
	}
	printf("\n");
}
