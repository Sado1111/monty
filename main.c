#include "monty.h"

int size_of_char(char *str, int *cmdsize, int *valsize)
{
	int i = 0, cmdstart = 0, valstart = 0;

	while (str[i] == ' ')
		i++;

	if (str[i] == '\0' || str[i] == '\n') {
		*cmdsize = 0;
		*valsize = 0;
		return 0;
	}

	cmdstart = i;

	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
		if ((str[i] < 'a' || str[i] > 'z') && str[i] != ' ') {
		*cmdsize = 0;
		*valsize = 0;
		return -1; 
		}
		i++;
	}
	*cmdsize = i - cmdstart;

	while (str[i] == ' ')
		i++;

	if (str[i] == '\0' || str[i] == '\n') {
		*valsize = 0;
		return 0;
	}

	valstart = i;

	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
		i++;

	*valsize = i - valstart;

	return 0;
}

/**
 * main - the entry point of the program
 * @ac: the number of command line argument
 * @argv: a variadic list of command line argument
 * Return: 0 on success. otherwise 1
*/

int main(int ac, char *argv[])
{
	FILE *file;
	char  *line = NULL, *cmd, *val;
	size_t read, len = 0;
	int numline = 0, cmdsize = 0, valsize = 0, retval, i;


	if (ac != 2)
	{
		fprintf(stderr, "Useage: %s <filename> \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while ((read = getline(&line, &len, file)) != -1)
	{
		numline++;
		// printf("Total read: %ld\n", read);
		// printf("\tline %d: %s\n", numline, line);
		retval = size_of_char(line, &cmdsize, &valsize);
		
		cmd = malloc(cmdsize + 1);
		val = malloc(valsize + 1);

		if (cmd == NULL || val == NULL)
		{
			return (1);
		}

		strncpy(cmd, strtok(line, " \t\n\r"), cmdsize);
		strncpy(val, strtok(NULL, " \t\n\r"), valsize);

		printf("%s --> %s\n", cmd, val);

	}

	free(line);
	fclose(file);
	return 0;
}
