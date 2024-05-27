NAME	= libftprintf.a

SRCS	= ./srcs/ft_printf.c \
		  ./srcs/ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re