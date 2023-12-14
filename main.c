#include "monty.h"
/**
 * main - Driver
 * @argc: Arg count
 * @argv: Arg vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	ssize_t read_val = 0;
	size_t n = 0;
	char *lp1 = NULL, *lp2 = NULL, **args = NULL;
	int count = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_val = getline(&lp1, &n, file);
	while (read_val != -1)
	{
		lp2 = strdup(lp1);
		count = count_tokens(lp1);
		args = fetch_tokens(lp2, count);
		free(lp2);
		err_check(lp1, &stack, args, file, line_number);
		get_func(args, lp1, &stack, line_number, file);
		line_number++;
		free_args(args);
		line_number++;
		read_val = getline(&lp1, &n, file);
	}
	free(lp1);
	fclose(file);
	_free(stack);
	return (0);
}
