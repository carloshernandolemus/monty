#include "monty.h"

/**
 * swap2top - Changes the order into the top elements
 * @stack: Is the pointer to stack mem addresss
 * @line_num: Is the current line number
 */
void swap2top(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp_node;
	int len = 0, swapopc;

	tmp_node = *stack;

	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(global.f_hand);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}

	tmp_node = *stack;
	swapopc = tmp_node->n;
	tmp_node->n = tmp_node->next->n;
	tmp_node->next->n = swapopc;
}

/**
 * rotate_top - Rotate the top of the stack
 * @stack: Is the pointer to stack mem address
 * @line_num: Is unused
 */
void rotate_top(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *rot_node = *stack;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tmp = (*stack)->next;
	tmp->prev = NULL;
	while (rot_node->next != NULL)
		rot_node = rot_node->next;
	rot_node->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = rot_node;
	(*stack) = tmp;
}

/**
 * rotate_bottom - Rotate the top of the stack
 * @stack: Is the pointer to stack mem address
 * @line_num: Is unused
 */
void rotate_bottom(stack_t **stack, unsigned int line_num)
{
	stack_t *rot_node = *stack;
	(void) line_num;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (rot_node->next)
		rot_node = rot_node->next;

	rot_node->next = *stack;
	rot_node->prev->next = NULL;
	rot_node->prev = NULL;
	(*stack)->prev = rot_node;
	(*stack) = rot_node;
}
