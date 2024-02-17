#include "helper_func.h"

int	num_exists(const unsigned int number, t_d_e *d, int *ds)
{
	int	i;

	i = 0;
	while (i < *ds)
	{
		if (d[i].number == number)
			return (1);
		i++;
	}
	return (0);
}

char	*get_number_string(unsigned int number, t_d_e *d, int *ds)
{
	static char	value[256];
	int			i;

	i = 0;
	while (i < *ds)
	{
		if (d[i].number == number)
		{
			ft_strncpy(value, d[i].value, sizeof(value) - 1);
			value[sizeof(value) - 1] = '\0';
			return (value);
		}
		i++;
	}
	return (NULL);
}

void	csm(unsigned int number, char *res, t_d_e *d, int *ds)
{
	int	i;

	i = 0;
	while (i < *ds)
	{
		if (d[i].number == number)
		{
			ft_strcat(res, d[i].value);
			ft_strcat(res, " ");
		}
		i++;
	}
}

void	free_dictionary(t_d_e *d, int *ds)
{
	int	i;

	i = 0;
	while (i < *ds)
	{
		free(d[i].value);
		i++;
	}
	free(d);
	free(ds);
}

unsigned int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;

	sign = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n')) 
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_print_string(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

