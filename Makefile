NAME = push_swap
NAME_B = checker
CFILES = check.c  ft_split.c helper_sort.c helper.c push_swap.c push.c reverse_rotate.c rotate.c sort_large.c\
		sort_small.c swap.c fun_main.c fun_algo.c

OBJ = ${CFILES:.c=.o}
FLAG = -Wall -Werror -Wextra #-fsanitize=address -g3
CC = cc
LI = ar rc
RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAG} ${OBJ} -o ${NAME}


clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re