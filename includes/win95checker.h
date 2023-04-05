#ifndef WIN_95_CHECKER_H
# define WIN_95_CHECKER_H
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define _RESET "\033[0;39m"
# define _RED "\033[0;91m"
# define _GREEN "\033[0;92m"

// src/main.c
int		check_oem(char *key);
int		check_ab(char *key);
int		check_pers(char *key);
int		check_first_part(char *key);
int		check_mod7(char *key);

// src/helpers.c
int		put_error(char *m1, char *m2);
int		put_res(char *m1, char *m2);
int		type_ok(char *s, int *t);

#endif