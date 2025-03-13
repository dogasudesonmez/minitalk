NAME= libftprintf.a
SRC= ft_printf.c ft_printf_utils.c
CC= cc 
CFLAGS= -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME) $(OBJ)
re: clean all
.PHONY: all clean fclean re
