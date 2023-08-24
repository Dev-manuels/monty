#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void) stack;
	(void) line_number;
	if (info_glob.nodes < 1)
	{
		printf("\n");
	}
	else
	{
		if (info_glob.cur_type == STACK && info_glob.nodes > 0)
		{
			head = info_glob.head;
		}
		else if (info_glob.cur_type == QUEUE && info_glob.nodes > 0)
		{
			head = info_glob.tail;
		}
		while (head)
		{
			if (head->n > 255 || head->n <= 0)
			{
				break;
			}
			printf("%c", head->n);
			head = head->next;
		}
		printf("\n");
	}
}
