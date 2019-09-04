NAME = ft_display_file
SRCS = main.c

.PHONY: all clean fclean

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
