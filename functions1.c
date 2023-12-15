#include "monty.h"

/**
 * count_tokens - A functions that counts the number of tokens in a string
 * @lp: The string
 * Return: The number of tokens
 */
int count_tokens(char *lp)
{
	int count = 0;
	char *token = NULL;

	token = strtok(lp, " \n");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \n");
	}
	return (count);
}

/**
 * tokenize - A function that breaks a string down to indidual tokens
 * @lp2: The string
 * @count: The number of tokens
 * @args: The string array where the string tokens will be stored
 * Return: The string array
 */
char **tokenize(char *lp2, int count, char **args)
{
	char *token = NULL;
	int i = 0;

	if (lp2 == NULL || args == NULL)
		return (NULL);
	token = strtok(lp2, " \n");
	for (i = 0; i < count; i++)
	{
		args[i] = strdup(token);
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	return (args);
}
/**
 * get_func - checks if opcode is valid and assigns function to
 *            execute if it is
 * @args: The string array holding the tokens
 * @stack: The pointer to the stack
 * @line_number: The line number of the opcode / instruction
 * @file: The opened file with the opcodes / instructions
 * @lp1: Line pointer
 */
void get_func(char **args, char *lp1, stack_t **stack,
		unsigned int line_number, FILE *file)
{
	instruction_t op_func[] = {
		{"push", &_push},
		{"pall", &_pall},
		{"pint", &_pint},
		{"pop", &_pop},
		{"swap", &_swap},
		{"add", &_add},
		{"nop", &_nop},
		{"sub", &_sub},
		{"div", &_div},
		{"mul", &_mul},
		{"mod", &_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (op_func[i].opcode != NULL)
	{
		if (strcmp(op_func[i].opcode, args[0]) == 0)
		{
			op_func[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
	free_args(args);
	free(lp1);
	_free(*stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
/**
 * _push - pushes an element onto the stack
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n;

	(void) line_number;
	n = atoi(args_num);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = n;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
}
/**
 * _pall - prints all the elements ina stack
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	if (*stack == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", (current->n));
		current = current->next;
	}
}
