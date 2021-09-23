#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct var_s - struct to contain the main variables of the Monty interpreter
 * @queue: flag to determine if in stack vs queue mode
 * @stack_len: length of the stack
 */
typedef struct var_s
{
	size_t stack_len;
} var_t;
/* global struct to hold flag for queue and stack length */
var_t var;
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

/*get_funs.c*/
void get_funs(char *token, stack_t **stack, unsigned int line_number);

/*push.c empujar un numero entero en la pila*/
void _push(stack_t **stack, unsigned int line_number);
/*pop.c sacar el elemento superior de la pila*/
void _pop(stack_t **stack, unsigned int line_munber);
/*pall.c imprime todos los valores en la pila comenzando desde arriba*/
void _pall(stack_t **stack, unsigned int line_munber);
/*add_node.c*/
stack_t *add_node(stack_t **stack, const int n);
/*free.c*/
void free_stack(int status, void *arg);
void free_line(int status, void *arg);
void f_close(int status, void *arg);
/*swap.c*/
void n_swap(stack_t **stack, unsigned int line_number);
/*add.c*/
void _add(stack_t **stack, unsigned int line_number);
/*nop.c*/
void _nop(stack_t **stack, unsigned int line_number);
/*pint.c*/
void _pint(stack_t **stack, unsigned int line_number);
/*sub.c*/
void _sub(stack_t **stack, unsigned int line_number);
/*div.c*/
void _div(stack_t **stack, unsigned int line_number);
#endif /*_MONTY_H_*/
