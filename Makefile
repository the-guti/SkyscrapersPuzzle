CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = main
SRC = main.c helper_func.c ft_strings.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)

.PHONY: all clean