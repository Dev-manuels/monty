#include "monty.h"

int isValidCmd(char *token, int line_number);
info_t info_glob = {0, STACK, 0, NULL, NULL, NULL, NULL, {{"push", push},
{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap}, {"nop", nop},
{"add", add}, {"sub", sub}, {"div", _div}, {"mul", _mul}, {"mod", _mod},
{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
{NULL, NULL}}};
/**
 * main - main program entry
 * @argc: argument count
 * @argv: argument #include "monty.h"
 * Return: 0 on success and 1 on failure
 */
int main(int argc, char **argv)
{
	stack_t *node;
	int rtVal = EXIT_FAILURE, line_number = 0, i = 0;

	atexit(free_stack);
	if (argc != 2)/* Check that the program recived two arguments */
		fprintf(stderr, "USAGE: monty file\n");
	else
	{
		FILE *file = fopen(argv[1], "r");/* Attempt to open file in Read mode */
		char line[200], *token, delim[] = " \n";

		/* Check if file was opened successful */
		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			return (EXIT_FAILURE);
		}
		/* Read from the file and tokenize the inputs line by line */
		while (fgets(line, sizeof(line), file) != NULL)
		{
			line_number++;
			/* Check if the current line is empty */
			if (is_empty(line) == 0)
				continue;
			token = strtok(line, delim);
			if (token[0] == '#')/* Handle Comments */
				continue;
			/* Check if the opcode is a valid command */
			if (isValidCmd(token, line_number) != 0)
			{
				fclose(file);
				exit(EXIT_FAILURE);
			}
			/* Proceed to handle the opcode */
			for (i = 0; info_glob.opcs[i].opcode != NULL; i++)
			{
				/* Check if the opcode is push which takes additional arg */
				if (strcmp(token, info_glob.opcs[0].opcode) == 0)
				{
					token = strtok(NULL, delim);
					/* Check if the following input is a valid int */
					if (is_number(token) == 0)
					{
					/* Check if the arg is a comment */
					if (token[0] == '#')
						break;
					info_glob.val = atoi(token);
					node = create_node();
					/* Call the push function */
					info_glob.opcs[0].f(&node, line_number);
					}
					else
					{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
					}
				} else if (strcmp(token, info_glob.opcs[i].opcode) == 0)
				{
					info_glob.opcs[i].f(NULL, line_number);
				}
			}
		}
		fclose(file);
		rtVal = EXIT_SUCCESS;
	}
	return (rtVal);
}

/**
 * isValidCmd - checks if token is valid opcode
 * @token: token to be checked
 * @line_number: line number
 * Return: 0 if valid else 1
 */
int isValidCmd(char *token, int line_number)
{
	int i = 0;
	char *sim[8] = {"add", "swap", "sub", "div", "mul", "mod", NULL};

	for (i = 0 ; sim[i] != NULL; i++)
	{
		if (strcmp(token, sim[i]) == 0 && info_glob.nodes <= 1)
		{
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, token);
			return (1);
		}
	}
	if (strcmp(token, "pint") == 0 && info_glob.nodes == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (1);
	}
	if (strcmp(token, "pchar") == 0 && info_glob.nodes == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		return (1);
	}
	if (strcmp(token, "pchar") == 0 && ((info_glob.cur_type == STACK
		&& ((info_glob.head)->n < 0 || (info_glob.head)->n > 127))
		|| (info_glob.cur_type == QUEUE && ((info_glob.tail)->n < 0
		|| (info_glob.tail)->n > 127))))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		return (1);
	}
	if ((strcmp(token, "div") == 0 || strcmp(token, "mod") == 0)
		&& (info_glob.head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		return (1);
	}
	if (strcmp(token, "pop") == 0 && info_glob.nodes < 1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return (1);
	}
	for (i = 0; info_glob.opcs[i].opcode != NULL; i++)
	{
		if (strcmp(token, info_glob.opcs[i].opcode) == 0)
			return (0);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	return (1);
}
/**
 * nop - function for nop operation
 * @stack: pointer to new node  to be pushed
 * @line_number: line number of opcode in monty file
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
