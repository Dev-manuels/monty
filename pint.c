#include "monty.h"
/**
 * pint - print value at the top of a stack/queue
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	if (info_glob.cur_type == STACK && info_glob.nodes > 0)
	{
		printf("%d\n", info_glob.head->n);
	}
	else if (info_glob.cur_type == QUEUE && info_glob.nodes > 0)
	{
		printf("%d\n", info_glob.tail->n);
	}
}
