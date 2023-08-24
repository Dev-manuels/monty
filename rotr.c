#include "monty.h"
/**
 * rotr - opcode rotr rotates the stack to the bottom
 * The last element of the stack becomes the
 * top element of the stack
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) stack;
	(void) line_number;
	if (info_glob.nodes > 1)
	{
		tmp = (info_glob.tail)->prev;
		tmp->next = NULL;
		(info_glob.head)->prev = (info_glob.tail);
		(info_glob.tail)->prev = NULL;
		(info_glob.tail)->next = (info_glob.head);
		(info_glob.head) = (info_glob.tail);
		(info_glob.tail) = tmp;
	}
}
