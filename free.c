#include "monty.h"

/**
 * free_stack - frees a stack_t data struct
 * @astack: a stack_t struct
 * Return: always void
 */

void free_stack(stack_t **astack)
{
	stack_t *tmp = *astack;

	while (tmp != NULL)
	{
		(*astack) = (*astack)->next;
		free(tmp);
		tmp = *astack;
	}
	*astack = NULL;
}
