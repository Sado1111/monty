#include "monty.h"

/**
 * pstr - prints the value at the top of the stack
 * @head: head pointer.
 * @line_number: the line number read.
 */

void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int val;

	(void)line_number;
	while (tmp != NULL)
	{
		val = tmp->n;
		if (val <= 0 || val > 127)
		{
			printf("\n");
			return;
		}
		printf("%c", val);
		tmp = tmp->next;
	}
	printf("\n");
}
