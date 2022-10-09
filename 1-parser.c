#include "monty.h"

/**
 * stack_init - initialize an empty stack
 *
 * Return: pointer to the new stack
 */
stack_t *stack_init(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = STACK;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}

/**
 * get_op_func - matches an operation with its corresponding function
 * @ops: the operation to be match
 *
 * Return: A pointer to the corresponding function
 */
void (*get_op_func(char *ops))(stack_t **, unsigned int)
{
	instruction_t func[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}
	};
	int i = 0;

	while (func[i].opcode)
		if (strcmp(ops, func[i++].opcode) == 0)
			return (func[--i].f);

	return (NULL);
}

/**
 * exec_monty - function to execute a monty bytecodes script
 * @line_fd: file descriptor for an open Monty bytecodes script
 *
 * Return: EXIT_SUCCESS on success,EXIT_FAILURE otherwise
 */
int exec_monty(FILE *line_fd)
{
	stack_t *stack = NULL;
	char *line_read = NULL, *toks_str = NULL;
	size_t len = 0;
	unsigned int line_num = 0;
	void (*op_func)(stack_t**, unsigned int);

	stack = stack_init();

	while (getline(&line_read, &len, line_fd) != -1)
	{
		line_num++;
		if (*line_read == '\n')
			continue;

		toks_str = strtok(line_read, DELIM);

		if (!toks_str || *toks_str == '#')
			continue;

		global.toks_num = strtok(NULL, DELIM);

		op_func = get_op_func(toks_str);
		if (!op_func)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_num, toks_str);
			global.err_status = EXIT_FAILURE;
			break;
		}

		op_func(&stack, line_num);
		if (global.err_status == EXIT_FAILURE)
			break;
	}
	free_stack(&stack);
	free(toks_str);

	return (global.err_status);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (1).
 *         If the stack_t is in queue mode - QUEUE (0).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
