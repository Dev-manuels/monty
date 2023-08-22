#include "monty.h"
/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	if (info_glob.nodes >= 2)
	{
		stack_t *temp;

		if (info_glob.cur_type == STACK)
		{
			temp = info_glob.head->next;
			temp->n %= info_glob.head->n;
			free(temp->prev);
			temp->prev = NULL;
			info_glob.head = temp;
			info_glob.nodes--;
		}
		else if (info_glob.cur_type == QUEUE)
		{
			temp = info_glob.tail->prev;
			temp->n %= info_glob.tail->n;
			free(temp->next);
			temp->next = NULL;
			info_glob.tail = temp;
			info_glob.nodes--;
		}
	}
}
