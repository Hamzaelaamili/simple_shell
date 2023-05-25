#include "shell.h"

int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);

/**
 * num_len - Counts the digit length of a number.
 * Return: The digit length.
 */
int num_len(int num)
{
	unsigned int num1;
	int leng = 1;

	if (num < 0)
	{
		leng++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		leng++;
		num1 /= 10;
	}

	return (len);
}

/**
 * _itoa - Converts an integer to a string.
 * Return: The converted string.
 */
char *_itoa(int num)
{
	char *buffer;
	int leng = num_len(num);
	unsigned int g;

	buffer = malloc(sizeof(char) * (leng + 1));
	if (!buffer)
		return (NULL);

	buffer[leng] = '\0';

	if (num < 0)
	{
		g = num * -1;
		buffer[0] = '-';
	}
	else
	{
		g = num;
	}

	leng--;
	do {
		buffer[leng] = (g % 10) + '0';
		g /= 10;
		leng--;
	} while (g > 0);

	return (buffer);
}


/**
 * create_error - Writes a custom error message to stderr.
 * Return: The error value.
 */
int create_error(char **args, int err)
{
	char *error;

	switch (err)
	{
	case -1:
		error = error_env(args);
		break;
	case 1:
		error = error_1(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			error = error_2_exit(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			error = error_2_syntax(args);
		else
			error = error_2_cd(args);
		break;
	case 126:
		error = error_126(args);
		break;
	case 127:
		error = error_127(args);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);

}
