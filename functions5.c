#include "monty.h"

/**
 * open_file - Opens an existing monty file to read instructions/ opcodes
 * @filename: The file to be opened
 * Return: The pointer to the file on success
 */
FILE *open_file(char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (file);
}
/**
 * _pchar - prints the char at the top of the stack, The integer stored at the
 * top of the stack is treated as the ascii value
 * of the character to be printed
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode / instruction
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	char c = (*stack)->n;

	(void) line_number;
	printf("%c\n", c);
}
/**
 * _pstr - Prints string starting at the top of the stack, followed by a new
 * line. The integer stored in each element of the stack is treated as the
 * ascii value of the character to be printed
 * @stack: Pointer to the stack
 * @line_number: The line number of the opcode in the file
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	char c;
	stack_t *tmp = NULL;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		c = tmp->n;
		if (tmp->n < 1 || tmp->n > 127)
			break;
		printf("%c", c);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * _rotl - Moves the top element of the stack to the end
 * @stack: Pointer to the stack
 * @line_number: The line number of the opcode in the file
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *place_holder = NULL;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	place_holder = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	*stack = place_holder->next;
	tmp->next = place_holder;
	place_holder->prev = tmp;
	place_holder->next = NULL;
}

