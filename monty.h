#ifndef _MONTY_H_
#define _MONTY_H_

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>


/*Structures*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct aux_s - Global representation
 * @val: integer
 * @file: points to the previous element of the stack (or queue)
 * @line_inf: points to the next element of the stack (or queue)
 * @flag_sq: 0 or 1 isf is a queue
 *
 */
typedef struct global_s
{
	char *p_data;
	FILE *f_hand;
	char *monty_line;
	int data_str;
} global_t;

/*Global definition*/
extern global_t global;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/*Functions*/

/*main*/
void freePlates(stack_t *stack);
int opcSelec(char *line_inf, stack_t **stack, unsigned int lnum, FILE *file);

/*maths*/
void addm(stack_t **stack, unsigned int line_num);
void subm(stack_t **stack, unsigned int line_num);
void mulm(stack_t **stack, unsigned int line_num);
void divm(stack_t **stack, unsigned int line_num);
void modm(stack_t **stack, unsigned int line_num);


/*actions*/
void push_data(stack_t **stack, unsigned int line_number);
void add_top(stack_t **stack, int push_data);
void add_last(stack_t **stack, int push_data);
void delete_top(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);


/*display*/
void print_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void printTopC(stack_t **stack, unsigned int line_number);
void printTopS(stack_t **stack, unsigned int line_number);

/*modifiers*/
void swap2top(stack_t **stack, unsigned int line_number);
void rotate_top(stack_t **stack, unsigned int line_number);
void rotate_bottom(stack_t **stack, unsigned int line_number);

/*data structures*/
void queuef(stack_t **stack, unsigned int line_number);
void stackf(stack_t **stack, unsigned int line_number);

#endif
