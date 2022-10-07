
#ifndef __MONTY_H__
#define __MONTY_H__


/* --------------To be able to use getline func---------------- */

#define  _POSIX_C_SOURCE 200809L

/* ============================================================ */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK 1 /* stack mode */
#define QUEUE 0 /* Queue mode */
#define DELIM " \n\t\r\a\b"
#define FAILURE -1




/* -----------Struct variables to build my stack or queue---------- */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* ================================================================ */



/* -----------link monty opcode to necessary function-------------- */

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* ================================================================ */




/* --------------------Global Struct variable---------------------- */

/**
 * struct global_s - global struct for monty variable
 * @err_status: error status to hold error term
 * @toks_num: number tokenized from the line read
 */
typedef struct global_s
{
	int err_status;
	char *toks_num;
} global_t;

extern global_t global;

/* ================================================================ */



/* -----------------Monty Handler(#1-parser.c)--------------------- */

int exec_monty(FILE *);
void (*get_op_func(char *ops))(stack_t **, unsigned int);
stack_t *stack_init(void);
int check_mode(stack_t *);

/* ================================================================ */



/* -------------monty Helper funcs(#2-helper_funcs.c)-------------- */

int is_digit(char *);
int stack_size(stack_t *);
stack_t *add_new_node(int);

/* ================================================================ */



/* -----------------------Monty Operations------------------------- */


/* -----------------(#3-handlers.c)------------------------ */

void push_handler(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack, unsigned int line_number);
void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);


/* -----------------(#4-handlers.c)------------------------ */

void div_handler(stack_t **stack, unsigned int line_number);
void mul_handler(stack_t **stack, unsigned int line_number);
void mod_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void sub_handler(stack_t **stack, unsigned int line_number);


/* -----------------(#5-handlers.c)------------------------ */

void pchar_handler(stack_t **stack, unsigned int line_number);
void pstr_handler(stack_t **stack, unsigned int line_number);
void rotl_handler(stack_t **stack, unsigned int line_number);
void rotr_handler(stack_t **stack, unsigned int line_number);


/* -----------------(#6-handlers.c)------------------------ */

void stack_handler(stack_t **stack, unsigned int line_number);
void queue_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);


/* ================================================================ */



/* ---------------Memory manager(#7-mem_management.c)-------------- */

void free_stack(stack_t **stack);

/* ================================================================ */



#endif /* __MONTY_H__ */
