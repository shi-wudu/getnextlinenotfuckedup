SRCS			=	get_next_line.c get_next_line_utils.c

NAME			=	gnl.a

OBJS			=	$(SRCS:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -D BUFFER_SIZE=1

all:		$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
					ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS)
					ar rcs $(NAME) $(OBJS)

clean:
					rm -f $(OBJS)

fclean: 	clean
					rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re