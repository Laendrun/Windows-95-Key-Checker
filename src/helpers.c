#include "win95checker.h"

int	put_error(char *m1, char *m2)
{
	dprintf(STDERR_FILENO, "%s", _RED);
	if (m1 && *m1)
		dprintf(STDERR_FILENO, "%s", m1);
	if (m2 && *m2)
		dprintf(STDERR_FILENO, "%s", m2);
	dprintf(STDERR_FILENO, "\n%s", _RESET);
	return (1);
}

int	put_res(char *m1, char *m2)
{
	if (!m2)
		dprintf(STDOUT_FILENO, "%s", _RED);
	else
		dprintf(STDOUT_FILENO, "%s", _GREEN);
	if (m1 && *m1)
		dprintf(STDOUT_FILENO, "%s", m1);
	if (m2 && *m2)
		dprintf(STDOUT_FILENO, "%s", m2);
	dprintf(STDOUT_FILENO, "\n%s", _RESET);
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