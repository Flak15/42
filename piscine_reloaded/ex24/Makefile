NAME = libft.a
INCLUDES = includes/
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c \
 srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
BINS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRCS) -I $(INCLUDES)
	@ar rc $(NAME) $(BINS)

clean:
	@rm -f $(BINS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
