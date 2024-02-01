#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @head: head pointer.
 * @line_number: the line number read.
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	if (temp->next)
	{
		(temp->next)->prev = NULL;
		*head = temp->next;
	}
	else
		*head = NULL;

	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @head: head pointer.
 * @line_number: the line number read.
 */

void swap(stack_t **head, unsigned int line_number)
{
	int a, b;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*head)->n;
	b = (*head)->next->n;

	(*head)->n = b;
	(*head)->next->n = a;

}


/**
 * add -  adds the top two elements of the stack.
 * @head: head pointer.
 * @line_number: the line number read.
 */

void add(stack_t **head, unsigned int line_number)
{
	int a, b, c;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;

	a = temp->n;
	b = temp->next->n;
	c = a + b;

	temp->next->n = c;
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * nop - doesn’t do anything.
 * @head: head pointer.
 * @line_number: the line number read.
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void) head, (void) line_number;
}

/**
 * sub - subtracts stack's top element from second top
 * @head: head pointer.
 * @line_number: the line number read
 */

void sub(stack_t **head, unsigned int line_number)
{
	int result;
	stack_t *top, *second_top;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *head;
	second_top = top->next;

	result = second_top->n - top->n;


	second_top->n = result;
	*head = second_top;
	second_top->prev = NULL;

	free(top);
}

