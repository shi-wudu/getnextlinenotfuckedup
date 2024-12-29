SRCS			=	get_next_line.c get_next_line_utils.c

NAME			=	gnl.a

LIBFT_PATH		=	./libft

LIBFT			=	./libft/libft.a

OBJS			=	$(SRCS:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

all:		$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS) $(LIBFT)
					ar rcs $(NAME) $(LIBFT) $(OBJS)
$(LIBFT):
					make -s -C $(LIBFT_PATH)

bonus:		$(OBJS)
					ar rcs $(NAME) $(OBJS) $(LIBFT)

clean:
					rm -f $(OBJS)

fclean: 	clean
					rm -f $(NAME) $(LIBFT)
					@make fclean -C $(LIBFT_PATH)

re:			fclean all

.PHONY: all clean fclean re