CC= cc
CFLAGS=-Wall -Wextra -Werror

NAME=client
NAME2=server
NAME_BONUS = client_bonus
NAME2_BONUS = server_bonus
#main items
SRC = client.c utils.c utils2.c
SRC2 = server.c utils.c utils2.c

#bonus items
SRC_BONUS = client_bonus.c utils.c utils2.c
SRC2_BONUS = server_bonus.c utils.c utils2.c


OBJ=$(SRC:.c=.o)
OBJ2=$(SRC2:.c=.o)

OBJ_BONUS=$(SRC_BONUS:.c=.o)
OBJ2_BONUS=$(SRC2_BONUS:.c=.o)

all: $(NAME) $(NAME2) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) -o $@ $^


bonus : $(NAME2_BONUS) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME2_BONUS): $(OBJ2_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(OBJ2) $(OBJ_BONUS) $(OBJ2_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME2) $(NAME_BONUS) $(NAME2_BONUS)

re: fclean all bonus
