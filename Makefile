NAME	= push_swap

CHECKER	= checker

SDIR	= src
ODIR	= obj
DIR_L	= libft

SRCS_PS	= push_swap.c

SRCS_C	= checker.c

SRCS_U	= push_swap_utils.c operations.c quick_sort.c

SRCS_L	= ft_strlen.c ft_strslen.c ft_atoi.c ft_atol.c ft_isdigit.c ft_isnum.c \
		  ft_strjoin.c ft_split.c ft_putstr.c \
		  ft_strchr.c ft_strdup.c ft_strncmp.c ft_strtrimchr.c ft_strupdate.c

OBJS_PS	= ${addprefix ${ODIR}/, ${SRCS_PS:.c=.o}}

OBJS_C	= ${addprefix ${ODIR}/, ${SRCS_C:.c=.o}}

OBJS_U	= ${addprefix ${ODIR}/, ${SRCS_U:.c=.o}}

OBJS_L	= ${addprefix ${DIR_L}/, ${SRCS_L:.c=.o}}

GCC		= gcc
#RM		= del
RM		= rm -f

LIBFT	= libft.a

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME} ${CHECKER}

${ODIR}/%.o:	${SDIR}/%.c
	${GCC} ${CFLAGS} -c $< -o $@

${LIBFT}:
	#MinGW32-Make re -C ${DIR_L}
	make re -C ${DIR_L}

${NAME}:	${LIBFT} ${OBJS_PS} ${OBJS_U} ${OBJS_L}
	${GCC} -o ${NAME} ${OBJS_PS} ${OBJS_U} ${DIR_L}/${LIBFT}

${CHECKER}:	${LIBFT} ${OBJS_C} ${OBJS_U} ${OBJS_L}
	${GCC} -o ${CHECKER} ${OBJS_C} ${OBJS_U} ${DIR_L}/${LIBFT}

clean:
	${RM} ${OBJS_PS} ${OBJS_C} ${OBJS_U}
	make clean -C ${DIR_L}

fclean:
	${RM} ${NAME}
	${RM} ${CHECKER}
	${RM} ${OBJS_PS} ${OBJS_C} ${OBJS_U}
	make fclean -C ${DIR_L}

re:	fclean all

.PHONY:	all clean fclean re
