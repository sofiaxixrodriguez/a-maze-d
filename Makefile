##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

CC=gcc

CFLAGS= -Wall -Wextra -g

SRC = 	src/main.c \
	src/my_str_to_word_array.c \
	src/lib.c \
	src/string_management.c \
	src/parse.c \
	src/check.c \
	src/add_elements.c \
	src/start_end.c \
	src/print_info.c \
	src/fill.c \
	src/algorithm.c \
	src/dijsktra.c

O_FILES = $(SRC:.c=.o)

NAME = amazed

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
