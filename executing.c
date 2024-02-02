#include "monty.h"

/**
 * executing - works on fd to perform stack ops on stack
 * @stack: address of the stack
 * @fd: the file descriptor of the opened file
 * Return: 0 on success. otherwise 1
 */

int executing(stack_t **stack, FILE *fd)
{
	char *line = NULL, *token, *cmd;
	ssize_t read, num_line = 0;
	size_t len = 0, ops_size, cmd_found, i;
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"divd", divd}, {"mul", mul}, {"mod", mod},
	};

	while ((read = getline(&line, &len, fd)) != -1)
	{
		num_line++, token = strtok(line, " \t\r\n");
		if (token != NULL)
		{
			cmd = strdup(token);
			if (cmd == NULL)
			{
				fprintf(stderr, "Memory allocation failed\n");
				free(line), fclose(fd), exit(EXIT_FAILURE);
			}
			cmd_found = 0, ops_size = sizeof(ops) / sizeof(ops[0]);
			for (i = 0; i < ops_size; i++)
			{
				if (strcmp(cmd, ops[i].opcode) == 0)
				{
					ops[i].f(stack, num_line), cmd_found = 1;
					break;
				}
			}
			if (!cmd_found)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n", num_line, cmd);
				free(line), free(cmd), fclose(fd);
				return (1);
			}
			free(cmd);
		}
	}
	free(line), fclose(fd);
	return (0);
}
