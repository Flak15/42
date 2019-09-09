NAME = libft.a

.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c *.c  
	@ar rc $(NAME) *.o

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
