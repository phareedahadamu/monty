#include "monty.h"

/**
 * _free - Frees a stack / doubly linked list
 * @stack: Pointer to the stack
 */
void _free(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
/**
 * _pint - Prints the top int in the stack
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - Removes the top element in a stack
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
/**
 * _swap - swaps the top to elements in the stack
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *second, *first;
	int count = 0;

	tmp = *stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}
/**
 * _add - Sums up the tops to elements in a stack and replaces them so
 *        the stack is one element less
 * @stack: Pointer to the stack doubly linked list
 * @line_number: The line number of the opcode / instruction
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *first, *second;
	int count = 0;

	tmp = *stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	second->n += first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
