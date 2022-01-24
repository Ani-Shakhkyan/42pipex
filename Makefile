NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
SRC = {wildcard *.c}
OBJ = $(SRC:c=o)
all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling pipex..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating pipex objects... %-10.10s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean: clean
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

