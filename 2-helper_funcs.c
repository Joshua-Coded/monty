#include "monty.h"

/**
 * is_digit - checkes if passed variable is digit
 * @var: number to be checked
 *
 * Return: 1 if is digit, 0 otherwise
 */
int is_digit(char *var)
{
	int i = 0;

	while (var[i])
	{
		if (var[i] == '-' && i++ == 0)
			continue;
		if (var[i] < '0' || var[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


/**
 * add_new_node - adds a node to a stack
 * @number: number value of the stack
 * Return: nothing
 */
stack_t *add_new_node(int number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}


/**
 * stack_size - gets the size of a stack
 * @stack: pointer to the stack
 * Return: the size
 */
int stack_size(stack_t *stack)
{
	int i = 0;
	stack_t *temp = stack;

	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
