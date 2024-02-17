#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include "helper_func.h"

char	*ft_strchr(const char *str, int ch);

char	*ft_strcat(char *dest, const char *src);

size_t	ft_strlen(const char *str);

int		ft_isspace(int ch);

char	*ft_strdup(const char *str);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif // FT_STRINGS_H