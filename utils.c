#include "monty.h"
/**
 * create_node - function that handles node creation
 * Return: pointer to new node or NULL on failure
*/
stack_t *create_node(void)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node != NULL)
	{
		new_node->n = info_glob.val;
		new_node->prev = NULL;
		return (new_node);
	}
	fprintf(stderr, "Error: malloc failed\n");
	free(new_node);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - function that frees all the nodes in a stack
*/
void free_stack(void)
{
	stack_t *current = info_glob.head;

	if (current != NULL)
	{
		while (current != NULL)
		{
			info_glob.head = current->next;
			free(current);
			current = info_glob.head;
		}
	}
}

/**
* is_empty - Function that returns the length of a string
* @str: string to be read
* Return: 0 if empty, 1 if not
*/
int is_empty(const char *str)
{
	int i;

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'))
			{
				return (1);
			}
		}
	} else
	{
		return (1);
	}

	return (0);
}

/**
 * is_number - checks if a string is a number
 * @str: string to check
 *
 * Return: 0 if the string is a number, else 1.
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (1);

	if (*str == '+' || *str == '-')
		++str;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (1);
		++str;
	}

	return (0);
}

/**
 * _strdup - custom strdup
 * @s: string to duplicate
 * Return: pointer to new string else NULL
*/
char *_strdup(const char *s)
{
	char *dup = NULL;

	if (s != NULL)
	{
		int len = strlen(s) + 1;

		dup = malloc(len);
		if (dup != NULL)
			strcpy(dup, s);
	}
	return (dup);
}
