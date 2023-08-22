#include "monty.h"
/**
 * pop - perform pop operation in a stack/queue
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) stack;
	(void) line_number;
	if (info_glob.cur_type == STACK && info_glob.nodes > 0)
	{
		current = info_glob.head;
		info_glob.head = current->next;
		free(current);
		info_glob.nodes--;
	}
	else if (info_glob.cur_type == QUEUE && info_glob.nodes > 0)
	{
		current = info_glob.tail;
		info_glob.tail = current->prev;
		free(current);
		info_glob.nodes--;
	}
}
