#include "monty.h"

/**
 * isdigit_on_str - checks if any non-digit is in str
 * @s: array of character to be checked
 * Return: 0 if str is NULL/contains non-digits
 */

int isdigit_on_str(char *s)
{
	if (*s == '-')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * push - pushes an element to the stack.
 * @head: head pointer.
 * @line_number: the line number read.
 */

void push(stack_t **head, unsigned int line_number)
{
	int n;
	char *token;
	stack_t *temp = *head;
	stack_t *new_node;

	if (head == NULL)
	{
		fprintf(stderr, "Stack is not present\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \n\r\t");
	if (token == NULL || isdigit_on_str(token) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		temp->prev = new_node;
	*head = new_node;
}

/**
 * pall - prints all values on stack, starting from top
 * @head: head pointer.
 * @line_number: the line number read.
 */

void pall(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	while (*head != NULL)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @head: head pointer.
 * @line_number: the line number read.
 */

void pint(stack_t **head, unsigned int __attribute__((unused)) line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
