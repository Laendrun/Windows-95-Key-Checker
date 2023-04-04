#include "win95checker.h"

int	main(int ac, char **av)
{
	int	type = -1;
	int res = 0;

	if (ac != 3)
		return (put_error("Usage: ./win95check <[OEM], [PERS]>, <key>", 0));
	if (!type_ok(av[1], &type))
		return (put_error("Type should be <OEM> or <PERS> (without <>)\n", 0));
	if (type == 1)
		res = check_oem(av[2]);
	// else
	// 	res = check_pers(av[2]);
	// print result depending on res variable
	printf("Result: [%d]\n", res);
	return (0);
}

// Valid OEM Key: 34505-OEM-0000007-13370
// OEM Key format: AAABB-OEM-XXXXXXX-CCCCC

int	check_oem(char *key)
{
	if (strlen(key) != 23)
		return (0);
	if (!check_ab(key))
		return (0);
	if (strncmp(key + 5, "-OEM-", 5))
		return (0);
	printf("First part (till -OEM-), okay\n");
	return (0);
}

int	check_ab(char *key)
{
	int i = 0;
	char buf[4];
	int tmp;
	while (i < 5)
	{
		if (!isdigit(key[i]))
			return (0);
		i++;
	}
	memcpy(buf, key, 3);
	buf[3] = '\0';
	tmp = atoi(buf);
	if (tmp < 0 || tmp > 365)
		return (0);
	memcpy(buf, key + 3, 2);
	buf[2] = '\0';
	tmp = atoi(buf);
	if (tmp < 3 || tmp > 95)
		return (0);
	return (1);
}
