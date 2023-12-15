#include "monty.h"
/**
 * _nop - Does nothing
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}
/**
 * free_args - Frees an array of strings
 * @args: The string array
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
/**
 * fetch_tokens - Fetches the tokens from a line pointer
 * @lp2: The line pointer
 * @count: The number of tokens
 * Return: An array of strings with the tokens
 */
char **fetch_tokens(char *lp2, int count)
{
	char **args = NULL;

	args = malloc(sizeof(char *) * (count + 1));
	args = tokenize(lp2, count, args);
	if (args[1] != NULL)
		args_num = args[1];
	else
		args_num = NULL;
	return (args);
}
/**
 * err_check_1 - Checks for errors and prints the error messages
 * @lp1: Line pointer
 * @stack: Pointer to the stack
 * @args: Array of strings holding tokens
 * @file: open file pointer of the opcodes / instructions
 * @line_number: line number of the opcode
 */
void err_check_1(char *lp1, stack_t **stack, char **args,
		FILE *file, unsigned int line_number)
{
	if ((strcmp(args[0], "push") == 0 && args[1] == NULL) || (strcmp(args[0],
					"push") == 0 && (atoi(args[1]) == 0 && strcmp(args[1], "0") != 0)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "pint") == 0 && *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "pop") == 0 && *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "swap") == 0 && (*stack == NULL ||
				(*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "add") == 0 && (*stack == NULL || (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[0], "sub") == 0 && (*stack == NULL || (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(lp1, stack, args, file);
		exit(EXIT_FAILURE);
	}
}
/**
 * free_all - frees all allocated memory before exiting
 * @lp1: Line pointer
 * @stack: Pointer to the stack
 * @args: Array of strings holding tokens
 * @file: open file pointer of the opcodes / instructions
 */
void free_all(char *lp1, stack_t **stack, char **args, FILE *file)
{
	free(lp1);
	_free(*stack);
	free_args(args);
	fclose(file);
}
