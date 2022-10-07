#include "monty.h"


/**
 * div_handler - divides the second top element of the
 * stack by the top element of the stack
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void div_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}
	if (!(*stack)->next->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;

	pop_handler(stack, line_no);
}

/**
 * mul_handler - multiplies the second top element of the stack with
 * the top element of the stack
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void mul_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;

	pop_handler(stack, line_no);
}

/**
 * mod_handler - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void mod_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}
	if (!(*stack)->next->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_handler(stack, line_no);
}


/**
 * add_handler - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void add_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;

	pop_handler(stack, line_no);
}

/**
 * sub_handler - subtracts the top element of the stack
 *				from the second top element
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void sub_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;

	pop_handler(stack, line_no);
}
