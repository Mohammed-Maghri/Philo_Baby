
SRC = parsing.c philo.c utils.c part.c uti.c main.c tch.c
SRC_BON = philo_bon/main.c philo_bon/tchi.c philo_bon/uti.c philo_bon/pars.c philo_bon/philo_part.c 
CC = cc

CFLAGS = -Wall -Wextra -Werror 

OBJS = ${SRC:.c=.o}

NAME = philo
NAME_BON = philo_bonus 

all : $(NAME)

bonus : $(NAME_BON)

$(NAME_BON):$(OBJS)
	$(CC) $(CFLAGS) $(SRC_BON) -o $(NAME_BON)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c philo_bon/philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME) $(NAME_BON)

re: fclean all