# -----------------------------------Makefile------------------------------------
NAME	= philo

# -----------------------------------Sources-------------------------------------

HEADER	= philo.h

PHILO_SRCS 	= main.c  \
				actions.c\
				init.c\
				utils.c\
				living.c\
				observer.c



PHILO_SRC	= ${PHILO_SRCS}

OBJS	= ${PHILO_SRC:.c=.o}

# -----------------------------------Compilation------------------------------------

CC		= cc #-g -fsanitize=address 

FLAGS	= -Wall -Wextra -Werror

RM		= rm -f

# -----------------------------------Libraries--------------------------------------

INCLUDES = philo.h

# -----------------------------------Rules------------------------------------------

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) 

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c -I. $< -o $@

re: fclean all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

# -----------------------------------.phony--------------------------------------

.PHONY: all clean fclean re