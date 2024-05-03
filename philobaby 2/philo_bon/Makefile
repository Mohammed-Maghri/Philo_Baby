SRC = main.c tchi.c uti.c pars.c philo_part.c other_file.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus 
OBJS = ${SRC:.c=.o}

all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c phil.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all