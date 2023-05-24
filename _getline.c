#include "shell_simple.h"
/**
 * input_buffer - buffers
 *
 * @i: inforamtion
 * @b: address of buffer
 * @l: address of length variable
 *
 * Return: bytes
 *
 */

ssize_t _buffer(i_t *i, char **b, size_t *l)
{
	ssize_t read = 0;
	size_t p = 0;

	if(!*l)
	{
		free(*b);
		*b = NULL;
		signal(SIGINT, sigintHandler);
if MY_GETLINE
		read = 

