#include "monty.h"

/**
* main - entry point of the program
* @ac: argument count
* @av: variadic arguments
* Return: 0 on Success. Otherwise 1
*/

int main(int ac, char *av[])
{
	char *token, *line = NULL;
	unsigned int line_number = 1;
	size_t len = 0;
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

	while ((getline(&line, &len, file_des)) != -1)
	{
		token = strtok(line, " \n\t\r");
		if (token == NULL)
		{
			line_number++;
			continue;
		}
		executing(token, &mystack, line_number);
		line_number++;
	}
	free(line);
	freedlist(mystack);
	fclose(file_des);
	return (0);
}
