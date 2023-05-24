#include <unistd.h>
/**
 * it writes the character c to stdout
 * Return to On success 1.
 * On the error -1 is returned and the error is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
