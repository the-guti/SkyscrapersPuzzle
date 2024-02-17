#ifndef HELPER_FUNC_H
# define HELPER_FUNC_H
# define MAX_DICT_ENTRIES 100
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include "ft_strings.h"

typedef struct s_d_e{
	unsigned int	number;
	char			*value;
}	t_d_e;

int				num_exists(const unsigned int number, t_d_e *d, int *ds);

char			*get_number_string(unsigned int number, t_d_e *d, int *ds);

void			csm(unsigned int number, char *res, t_d_e *d, int *ds);

void			free_dictionary(t_d_e *d, int *ds);

unsigned int	ft_atoi(const char *str);

void			ft_print_string(const char *str);

#endif // HELPER_FUNC_H