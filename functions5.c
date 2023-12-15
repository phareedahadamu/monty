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
