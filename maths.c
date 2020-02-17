#include "monty.h"

/**
 * addm - Function to add
 * @stack: Is the pointer to the stack mem address
 * @line_num: Is the actual line number
 */
void addm(stack_t **stack, unsigned int line_num)
{
	stack_t *pl_node;
	int len = 0, add;

	pl_node = *stack;
	while (pl_node != NULL)
	{
		pl_node = pl_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	pl_node = *stack;
	add = pl_node->n + pl_node->next->n;
	pl_node->next->n = add;
	*stack = pl_node->next;
	free(pl_node);
}

/**
 * subm - Function to substract
 * @stack: Is the pointer to the stack mem address
 * @line_num: Is the actual line number
 */
void subm(stack_t **stack, unsigned int line_num)
{
	stack_t *pl_node;
	int sub, len = 0;

	pl_node = *stack;
	while (pl_node != NULL)
	{
		pl_node = pl_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	pl_node = *stack;
	sub = pl_node->next->n - pl_node->n;
	pl_node->next->n = sub;
	*stack = pl_node->next;
	free(pl_node);

}

/**
 * mulm - Function to multiply
 * @stack: Is the pointer to the stack mem address
 * @line_num: Is the actual line number
 */
void mulm(stack_t **stack, unsigned int line_num)
{
	stack_t *pl_node;
	int mul, len = 0;

	pl_node = *stack;
	while (pl_node != NULL)
	{
		pl_node = pl_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	pl_node = *stack;
	mul = pl_node->next->n * pl_node->n;
	pl_node->next->n = mul;
	*stack = pl_node->next;
	free(pl_node);

}


/**
 * divm - Function to divide
 * @stack: Is the pointer to the stack mem address
 * @line_num: Is the actual line number
 */
void divm(stack_t **stack, unsigned int line_num)
{
	stack_t *pl_node;
	int div, len = 0;

	pl_node = *stack;
	while (pl_node != NULL)
	{
		pl_node = pl_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	pl_node = *stack;
	if (pl_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);

	}
	div = pl_node->next->n / pl_node->n;
	pl_node->next->n = div;
	*stack = pl_node->next;
	free(pl_node);

}

/**
 * modm - Function to find the module
 * @stack: Is the pointer to the stack mem address
 * @line_num: Is the actual line number
 */
void modm(stack_t **stack, unsigned int line_num)
{
	stack_t *pl_node;
	int div, len = 0;

	pl_node = *stack;
	while (pl_node != NULL)
	{
		pl_node = pl_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	pl_node = *stack;
	if (pl_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);

	}
	div = pl_node->next->n % pl_node->n;
	pl_node->next->n = div;
	*stack = pl_node->next;
	free(pl_node);
}
