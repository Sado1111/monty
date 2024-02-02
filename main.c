#include "monty.h"

/**
* main - entry point of the program
* @ac: argument count
* @av: variadic arguments
* Return: 0 on Success. Otherwise 1
*/

int main(int ac, char *av[])
{
	char *token;
	unsigned int line_number = 1;
	stack_t *mystack = NULL;
	FILE *file_des;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_des = fopen(av[1], "r");
	if (file_des == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fd)) != -1)
	{
		token = strtok(buffer, " \n\t\r");
		if (token == NULL)
		{
			line_number++;
			continue;
		}
		executing(token, &stack, line_number);
		line_number++;
	}
	free(line);
	freedlist(stack);
	fclose(file);
	return (0);
}
