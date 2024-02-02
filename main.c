#include "monty.h"

/**
* main - entry point of the program
* @ac: argument count
* @av: variadic arguments
* Return: 0 on Success. Otherwise 1
*/

int main(int ac, char *av[])
{
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

	exit(executing(&mystack, file_des));
}
