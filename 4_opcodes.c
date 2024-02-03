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

/**
 * rotl - rotates the top to the last one and second top becomes first
 * @head: head pointer.
 * @line_number: the line number read.
 * Return: always void
 */

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp, *top_element;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		return;
	tmp = top_element = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	(top_element->next)->prev = NULL;
	*head = (top_element)->next;
	tmp->next = top_element;
	top_element->prev = tmp;
	top_element->next = NULL;
}
