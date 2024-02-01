#include "monty.h"

/**
 * divd - divides stack's second top element by top element
 * @head: head pointer.
 * @line_number: the line number read.
 */

void divd(stack_t **head, unsigned int line_number)
{
	int result;
	stack_t *top, *second_top;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *head;
	second_top = top->next;

	result = second_top->n / top->n;


	second_top->n = result;
	*head = second_top;
	second_top->prev = NULL;

	free(top);
}

/**
 * mul - multiplies stack's second top element by top element
 * @head: head pointer.
 * @line_number: the line number read.
 */

void mul(stack_t **head, unsigned int line_number)
{
	int result;
	stack_t *top, *second_top;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *head;
	second_top = top->next;

	result = second_top->n * top->n;


	second_top->n = result;
	*head = second_top;
	second_top->prev = NULL;

	free(top);
}

/**
 * mod - gets rest of division of stack's second top by top
 * @head: head pointer.
 * @line_number: the line number read.
 */

void mod(stack_t **head, unsigned int line_number)
{
	int result;
	stack_t *top, *second_top;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *head;
	second_top = top->next;

	result = second_top->n / top->n;


	second_top->n = result;
	*head = second_top;
	second_top->prev = NULL;

	free(top);
}
