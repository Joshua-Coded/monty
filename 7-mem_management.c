#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: the stack to free
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
