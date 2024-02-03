#include "monty.h"

/**
 * execute_line - tokenize a line and calls a function
 * @mystack: a stack to be operated on
 * @fd: file descriptor of the passed file to monty
 * @buffer: hold value of each line
 * @line_numb: the number of the current line in fd
 * Return: always void
 */

void execute_line(
	stack_t **mystack, FILE *fd, char **buffer, unsigned int line_numb)
{
	char *token, *cmd;
	size_t cmd_found = 0, ops_size, i;
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"pchar", pchar},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"pint", pint},
		{"sub", sub}, {"div", divd}, {"mul", mul}, {"mod", mod},
		{"pstr", pstr}, {"rotl", rotl},
	};

	token = strtok(*buffer, " \t\r\n");
	if (token != NULL)
	{
		cmd = strdup(token);
		if (cmd == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			free(buffer), fclose(fd), exit(EXIT_FAILURE);
		}
		if (cmd[0] == '#')
		{
			free(cmd);
			return;
		}
		ops_size = sizeof(ops) / sizeof(ops[0]);
		for (i = 0; i < ops_size; i++)
		{
			if (strcmp(cmd, ops[i].opcode) == 0)
			{
				ops[i].f(mystack, line_numb), cmd_found = 1;
				break;
			}
		}
		if (!cmd_found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_numb, cmd);
			free(*buffer), free(cmd), fclose(fd);
			exit(1);
		}
		free(cmd);
	}
}

/**
 * executing - works on fd to perform stack ops on stack
 * @stack: address of the stack
 * @fd: the file descriptor of the opened file
 * Return: 0 on success. otherwise 1
 */

int executing(stack_t **stack, FILE *fd)
{
	char *line = NULL;
	ssize_t read, num_line = 0;
	size_t len = 0;

	while ((read = getline(&line, &len, fd)) != -1)
	{
		num_line++;
		execute_line(stack, fd, &line, num_line);
	}
	free(line), fclose(fd);
	return (0);
}
