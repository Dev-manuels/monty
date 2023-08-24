#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) stack;
	(void) line_number;
	if (info_glob.nodes > 1)
	{
		tmp = (info_glob.head)->next;
		tmp->prev = (info_glob.head)->prev;
		(info_glob.tail)->next = info_glob.head;
		(info_glob.head)->next = NULL;
		(info_glob.head) = tmp;
	}
}
