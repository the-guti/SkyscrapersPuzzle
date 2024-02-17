#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "helper_func.h"
#include "ft_strings.h"

int parse_dictionary(const char *filename, t_d_e *d, int * ds)
{
    char line[256];
    int number;
    FILE *file = fopen(filename, "r");
    if(file == NULL)
        return 0;
    
    while (fgets(line, sizeof(line), file))
    {
        char *colon = ft_strchr(line, ':');
        if (colon == NULL) {
            fclose(file);
            return (0);
        }

        *colon = '\0';
        number = ft_atoi(line);
        char *value = colon + 1;

        while (ft_isspace(*value))
            value++;
        char *end = value + ft_strlen(value) - 1;
        while (end > value && ft_isspace(*end))
        {
            *end = '\0';
            end--;
        }
        if (*ds < MAX_DICT_ENTRIES)
        {
            d[*ds].number = number;
            d[*ds].value = ft_strdup(value);
            *ds = *ds + 1;
        } 
        else 
        {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

void convert_to_words(unsigned int number, t_d_e *d, int * ds)
{
    char *answer = malloc(1024);
    long long int limit;
	long long int curr_hun;
	long long int t;

	limit = 1000000000000;
	t = 0;
    if (answer == NULL)
	{
        ft_print_string("Error allocating memory\n");
        exit(1);
    }
    answer[0] = '\0';

    if (number == 0)
        csm(number, answer, d, ds);

    while (number > 0)
	{
        curr_hun = number / limit;
        while (curr_hun == 0 && limit > 1)
		{
            limit /= 1000;
            curr_hun = number / limit;
        }
        if (curr_hun > 99 && num_exists(curr_hun / 100, d, ds))
		{
            csm(curr_hun / 100, answer, d, ds);
            csm(100, answer, d, ds);
        }
        curr_hun = curr_hun % 100;

        if (curr_hun > 0 && curr_hun < 20)
		{
            if (num_exists(curr_hun, d, ds)) 
                csm(curr_hun, answer,   d, ds);
        } 
		else if (curr_hun % 10 == 0 && curr_hun != 0) 
		{
            if (num_exists(curr_hun, d, ds))
                csm(curr_hun, answer, d, ds);
        }
		else if (curr_hun > 20 && curr_hun < 100)
		{
            if (num_exists(curr_hun / 10 * 10, d, ds) && num_exists(curr_hun % 10, d, ds))
			{
                ft_strcat(answer, get_number_string(curr_hun / 10 * 10, d, ds));
                ft_strcat(answer, "-");
                csm(curr_hun % 10, answer, d, ds);
            }
        } 
        if (t < *ds - 1)
		{
            if (num_exists(limit, d, ds)&& limit > 100) 
                csm(limit, answer, d, ds);
            t++;
        }
        number %= limit;
        limit /= 1000;
    }
    ft_print_string(answer);
    free(answer);
}

int main(int argc, char *argv[])
{
    unsigned int number;
    char *d_name;
    t_d_e *d;
    int *ds = malloc(sizeof(int)); 

    if (ds == NULL) {
        ft_print_string("Memory allocation failed!\n");
        return 1;
    }
    *ds = 0;
    if (argc < 2 || argc > 3) {
        ft_print_string("Error\n");
        return 1;
    }

    number = ft_atoi(argv[argc - 1]);

    if (number < 0) {
        ft_print_string("Error\n");
        return 1;
    }

    d = malloc(MAX_DICT_ENTRIES * sizeof(t_d_e));

    if (argc == 3)
        d_name = argv[1];
    else
        d_name = "numbers.dict";

    if (!(parse_dictionary(d_name, d, ds))) {
            ft_print_string("Dict Error\n");
            return 1;
    }
    if (argc == 2)
        convert_to_words(number, d, ds);
    if (argc == 3)
        free_dictionary(d, ds);
    return 0;
}
