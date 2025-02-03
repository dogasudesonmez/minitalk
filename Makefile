NAME_C = client
NAME_S = server
NAME_BONUS_C = client_bonus
NAME_BONUS_S = server_bonus
SOURCES_C = client.c
SOURCES_S = server.c
LIBFT = libft.a

BSOURCES_C = client_bonus.c
BSOURCES_S = server_bonus.c


OBJECTS_C = $(SOURCES_C:.c=.o)
BOBJECTS_C = $(BSOURCES_C:.c=.o)
OBJECTS_S = $(SOURCES_S:.c=.o)
BOBJECTS_S = $(BSOURCES_S:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJECTS_C)
	$(CC) $(CFLAGS) $(OBJECTS_C) ./libft/$(LIBFT) -o $(NAME_C)

$(NAME_S): $(OBJECTS_S)
	$(CC) $(CFLAGS)  $(OBJECTS_S) -o $(NAME_S)
clean:
	rm -f $(OBJECTS_C) $(BOBJECTS_C) $(OBJECTS_S) $(BOBJECTS_S)

fclean: clean
	rm -f $(NAME_C) $(NAME_S) $(NAME_BONUS_S) $(NAME_BONUS_C)

bonus: all $(BOBJECTS_C) $(BOBJECTS_S)

$(NAME_BONUS_C): $(BOBJECTS_C)
	$(CC) $(CFLAGS) $(NAME_BONUS_C) $(BOBJECTS_C) ./libft/$(LIBFT)

$(NAME_BONUS_S): $(BOBJECTS_S)
	$(CC) $(CFLAGS) $(NAME_BONUS_S) $(BOBJECTS_S)

re: fclean all

.PHONY: all clean fclean re bonus bonus