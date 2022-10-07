#include "monty.h"


global_t global = {EXIT_SUCCESS, NULL};

/**
 * main - starting point for monty interpreter
 *
 * @argc: arguement count
 * @argv: list of arguement passed to the function
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	FILE *monty_fd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_fd = fopen(argv[1], "r");

	if (!monty_fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	global.err_status = exec_monty(monty_fd);
	fclose(monty_fd);

	exit(global.err_status);
}
