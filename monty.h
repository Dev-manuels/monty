#ifndef _MONTY_H_
#define _MONTY_H_

/* Required Headers */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Marcros */
#define STACK 1
#define QUEUE 0

/* Required Struct */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Custom Struct */
/**
 * struct info_s - struct to store global needed info
 * @head: pointer to the start of a stack/queue
 * @tail: pointer to the tail of a stack/queue
 * @val: opcode argument
 * @cur_type: current data type (STACK/QUEUE)
 * @nodes: total number of nodes
 * @file: name monty input file
 * @cmd: opcode on each line
 * @opcs: list of valid opcodes
 */
typedef struct info_s
{
	int val;
	int cur_type;
	int nodes;
	char *file;
	char *cmd;
	stack_t *head;
	stack_t *tail;
	instruction_t opcs[17];
} info_t;

extern info_t info_glob;

/* Function Prototypes */
void add(stack_t **stack, unsigned int line_number);
stack_t *create_node(void);
void _div(stack_t **stack, unsigned int line_number);
void free_stack(void);
int is_empty(const char *str);
int is_number(char *str);
int isValidCmd(char *token, int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
char *_strdup(const char *s);
void sub(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

#endif
