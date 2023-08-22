#include "monty.h"
/**
 * swap - swaps the top two elements of the stack\queue
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void swap(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	if (info_glob.nodes >= 2)
	{
		int temp = 0;

		if (info_glob.cur_type == STACK && info_glob.nodes >= 2)
		{
			temp = info_glob.head->n;
			info_glob.head->n = info_glob.head->next->n;
			info_glob.head->next->n = temp;
		}
		else if (info_glob.cur_type == QUEUE && info_glob.nodes >= 2)
		{
			temp = info_glob.tail->n;
			info_glob.tail->n = info_glob.tail->prev->n;
			info_glob.tail->prev->n = temp;
		}
	}
}
