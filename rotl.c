#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * The top element of the stack becomes the last one, 
 * and the second top element of the stack becomes the first one
 * @stack: pointer
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
		(info_glob.head)->prev = info_glob.tail;
		 info_glob.tail =  info_glob.head;
		(info_glob.head) = tmp;
	}
}
