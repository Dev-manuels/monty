#include "monty.h"
/**
 * pall - function for pall operation
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) stack;
	(void) line_number;
	if (info_glob.cur_type == STACK)
	{
		current = info_glob.head;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	} else
	{
		current = info_glob.tail;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->prev;
		}
	}
}
