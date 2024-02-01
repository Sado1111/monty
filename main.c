#include "monty.h"

int main(int ac, char *av[])
{
	stack_t *mystack = NULL;
	FILE *file_des;

	if (ac != 2)
	{
		fprintf(stderr, "Useage: %s <filename>\n", av[0]);
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
