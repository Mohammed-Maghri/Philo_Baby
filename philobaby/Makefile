
SRC = parsing.c philo.c utils.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRC:.c=.o}

NAME = philosophers

all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all