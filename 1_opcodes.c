#include "monty.h"

/**
 * isdigit_on_str - checks if any non-digit is in str
 * @str: array of character to be checked
 * Return: 0 if str is NULL/contains non-digits
 */

int isdigit_on_str(char *str)
{
	int i = 0;

	if (str[i] == '\0')
		return (0);

	while (str[i])
	{
		if (str[i] == '-')
			i++;

		if (!isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * new_node - creates a new node
 * @value: value to be passed to new node created
 * Return: pointer to new node created
 */

stack_t *new_node(int value)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}
/**
 * push - pushes an element to the stack.
 * @head: head pointer.
 * @line_number: the line number read.
 */

void push(stack_t **head, unsigned int line_number)
{
	char *token;
	int value;
	stack_t *new_top;

	token = strtok(NULL, " \t\r\n");

	if (token == NULL || !(isdigit_on_str(token)))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);
	if (*head == NULL)
	{
		*head = new_node(value);
		return;
	}

	new_top = new_node(value);
	new_top->next = *head;
	(*head)->prev = new_top;

	*head = new_top;
}

/**
 * pall - prints all values on stack, starting from top
 * @head: head pointer.
 * @line_number: the line number read.
 */

void pall(stack_t **head, unsigned int __attribute__((unused)) line_number)
{
	stack_t *temp;

	temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
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
