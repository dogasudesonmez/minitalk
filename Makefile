NAME_C = client
NAME_S = server
NAME_BONUS_C = client_bonus
NAME_BONUS_S = server_bonus
SOURCES_C = client.c
SOURCES_S = server.c

LIBFT_DIR = libft
PRINTF_DIR = printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

BSOURCES_C = client_bonus.c
BSOURCES_S = server_bonus.c


OBJECTS_C = $(SOURCES_C:.c=.o)
BOBJECTS_C = $(BSOURCES_C:.c=.o)
OBJECTS_S = $(SOURCES_S:.c=.o)
BOBJECTS_S = $(BSOURCES_S:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror


all:  $(LIBFT) $(PRINTF) $(NAME_C) $(NAME_S)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME_C): $(OBJECTS_C)
	$(CC) $(CFLAGS) $(OBJECTS_C) $(LIBFT) $(PRINTF) -o $(NAME_C)

$(NAME_S): $(OBJECTS_S)
	$(CC) $(CFLAGS)  $(OBJECTS_S) $(PRINTF) -o $(NAME_S)

clean:
	rm -f $(OBJECTS_C) $(BOBJECTS_C) $(OBJECTS_S) $(BOBJECTS_S)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME_C) $(NAME_S) $(NAME_BONUS_S) $(NAME_BONUS_C)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

bonus: $(NAME_BONUS_S) $(NAME_BONUS_C) $(BOBJECTS_C) $(BOBJECTS_S)

$(NAME_BONUS_C): $(BOBJECTS_C)
	$(CC) $(CFLAGS) $(BOBJECTS_C) $(LIBFT) $(PRINTF) -o $(NAME_BONUS_C)

$(NAME_BONUS_S): $(BOBJECTS_S)
	$(CC) $(CFLAGS) $(BOBJECTS_S) $(PRINTF) -o $(NAME_BONUS_S)

re: fclean all

.PHONY: all clean fclean re bonus