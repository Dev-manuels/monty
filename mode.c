#include "monty.h"
/* Handles switching between stack and queue mode of operation */
/**
 * _stack - print char at the top of a stack/queue
 * @stack: pointer
 * @line_number: line number of opcode in monty file
*/
void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	info_glob.cur_type = STACK;
}

/**
 * _queue - print char at the top of a stack/queue
 * @stack: pointer
 * @line_number: line number of opcode in monty file
*/
void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	info_glob.cur_type = QUEUE;
}
