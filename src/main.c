#include "win95checker.h"

int	main(int ac, char **av)
{
	int	type = -1;
	int res = 0;

	if (ac != 3)
		return (put_error("Usage: ./win95check <[OEM], [PERS]>, <key>", 0));
	if (!type_ok(av[1], &type))
		return (put_error("Type should be <OEM> or <PERS> (without <>)", 0));
	if (type)
		res = check_oem(av[2]);
	else
		res = check_pers(av[2]);
	if (type && res)
		return (put_res("Valid OEM Key: ", av[2]));
	if (type && !res)
		return (put_res("Invalid OEM Key.", 0));
	if (!type && res)
		return (put_res("Valid PERS Key: ", av[2]));
	if (!type && !res)
		return (put_res("Invalid PERS Key.", 0));
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
	if (!check_mod7(key + 10))
		return (0);
	if (*(key + 17) != '-')
		return (0);
	return (1);
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

// Valid personal key: 000-0000000
// Valid personal key format: XXX-YYYYYYY
int	check_pers(char *key)
{
	if (strlen(key) != 11)
		return (0);
	if (!check_first_part(key))
		return (0);
	if (!check_mod7(key + 4))
		return (0);
	return (1);
}

int	check_first_part(char *key)
{
	if (!strncmp(key, "333", 3) || !strncmp(key, "444", 3)
		|| !strncmp(key, "666", 3) || !strncmp(key, "777", 3)
		|| !strncmp(key, "888", 3) || !strncmp(key, "999", 3))
		return (0);
	return (1);
}

int	check_mod7(char *key)
{
	char buf[8];
	int sum = 0;
	int i = 0;

	memcpy(buf, key, 7);
	buf[7] = '\0';
	while (i < 7)
	{
		if (!isdigit(buf[i]))
			return (0);
		sum += buf[i] - 48;
		i++;
	}
	if (sum % 7 != 0)
		return (0);
	return (1);
}
