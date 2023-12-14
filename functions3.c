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
char *args_num;
char **fetch_tokens(char *lp2, int count)
{
	char **args = NULL;

	args = malloc(sizeof(char *) * (count + 1));
	args = tokenize(lp2, count, args);
	if (count > 1)
		args_num = args[1];
	else
		args_num = NULL;
	return (args);
}
