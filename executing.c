#include "monty.h"

/**
 * executing - works on fd to perform stack ops on stack
 * @cmd: command
 * @head: address of the stack
 * @line_number: no of line read
 */


void executing(char *cmd, stack_t **head, int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"div", divd},
		{"mul", mul},
		{"mod", mod},
	};

	if (*cmd == '#')
		return;

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, cmd) == 0)
		{
			ops[i].f(head, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}


/**
 * freedlist - frees a list.
 * @head: head pointer.
 */
void freedlist(stack_t *head)
{
	stack_t *current =  NULL, *next = NULL;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
