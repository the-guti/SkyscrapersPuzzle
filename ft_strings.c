#include "ft_strings.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str != '\0') {
		length++;
		str++;
	}

	return (length);
}

char	*ft_strcat(char *dest, const char *src)
{
	char* dest_end = dest;
	while (*dest_end != '\0')
		dest_end++;
	while (*src != '\0')
	{
		*dest_end = *src;
		dest_end++;
		src++;
	}
	*dest_end = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char*)str); 
		str++;
	}
	return (NULL);
}

int ft_isspace(int ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v');
}

char	*ft_strdup(const char *str)
{
	size_t len = ft_strlen(str) + 1; 
	char* new_str = (char*)malloc(len * sizeof(char));

	if (new_str == NULL) {
		ft_print_string("Memory allocation failed!\n");
		return (NULL);
	}

	ft_strcpy(new_str, str);
	return (new_str);
}

char *ft_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

char *ft_strncpy(char *dest, const char *src, size_t n) {
	char *original_dest = dest;

	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (original_dest);
}
