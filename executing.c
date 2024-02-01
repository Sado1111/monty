#include "monty.h"

int executing(stack_t **stack, FILE *fd)
{
	char *line = NULL, *cmd;
	size_t read, len = 0;
	unsigned int num_line = 0, cmd_found, i, ops_size;
	instruction_t ops[] = {
		{"push", push}, {"pall", pall},
	};

	while (read = getline(&line, &len, fd) != -1)
	{
		num_line++;
		cmd_found = 0;
		cmd = strtok(line, " \t\r\n");
		if (cmd != NULL)
			cmd = strdup(cmd);
		else
			continue;

		ops_size = sizeof(ops) / sizeof(ops[0]);

		for (i = 0; i < ops_size; i++)
		{
			if (strcmp(cmd, ops[i].opcode) == 0)
			{
				ops[i].f(stack, num_line);
				cmd_found = 1;
				break;
			}
		}
		if (!cmd_found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", num_line, cmd);
			free(line);
			free(cmd);
			fclose(fd);
			return (1);
		}
		free(cmd);
	}
	free(line);
	fclose(fd);
	return (0);
}
