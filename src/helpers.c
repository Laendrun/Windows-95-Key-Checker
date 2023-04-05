#include "win95checker.h"

int	put_error(char *m1, char *m2)
{
	while (m1 && *m1)
		write(STDERR_FILENO, m1++, 1);
	while (m2 && *m2)
		write(STDERR_FILENO, m2++, 2);
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

int	put_res(char *m1, char *m2)
{
	while (m1 && *m1)
		write(STDOUT_FILENO, m1++, 1);
	while (m2 && *m2)
		write(STDOUT_FILENO, m2++, 1);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

int	type_ok(char *s, int *t)
{
	if (!strncmp(s, "OEM", 4))
	{
		*t = 1;
		return (1);
	}
	if (!strncmp(s, "PERS", 5))
	{
		*t = 0;
		return (1);
	}
	return (0);
}