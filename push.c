#include "monty.h"
/**
 * push - function for push operation
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(*stack)->next = info_glob.head;
	if (info_glob.head != NULL)
		info_glob.head->prev = *stack;
	if (info_glob.tail == NULL)
		info_glob.tail = *stack;
	info_glob.head = *stack;
	info_glob.nodes++;
}
