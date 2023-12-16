#include "monty.h"

/**
 * _sub - Subtracts the top element from the second one in a stack and
 * replaces them so the stack is one element less
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	(void) line_number;
	first = *stack;
	second = (*stack)->next;
	second->n -= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
/**
 * _div - Divides the top element by the second one in a stack and
 * replaces them so the stack is one element less
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	(void) line_number;
	first = *stack;
	second = (*stack)->next;
	second->n /= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
/**
 * _mul - Multiplies the top two elements in a stack and
 * replaces them so the stack is one element less
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	(void) line_number;
	first = *stack;
	second = (*stack)->next;
	second->n *= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	(void) line_number;
	first = *stack;
	second = (*stack)->next;
	second->n %= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
/**
 * err_check_2 - Checks for errors and prints the error messages
 * @lp1: Line pointer
 * @stack: Pointer to the stack
 * @args: Array of strings holding tokens
 * @file: open file pointer of the opcodes / instructions
 * @line_number: line number of the opcode
 */
void err_check_2(char *lp1, stack_t **stack, char **args,
		FILE *file, unsigned int line_number)
{
	if (strcmp(args[0], "div") == 0 && (*stack == NULL || (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "div") == 0 && (*stack != NULL && (*stack)->next != NULL)
			&& (*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "mul") == 0 && (*stack == NULL || (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
				line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "mod") == 0 && (*stack == NULL || (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
				line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "mod") == 0 && (*stack != NULL && (*stack)->next != NULL)
			&& (*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "pchar") == 0 && *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "pchar") == 0 && (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
}
