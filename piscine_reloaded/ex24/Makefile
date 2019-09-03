NAME = libft.a
INCLUDES = includes/
FUNCTIONS = srcs/ft_putchar.c srcs/ft_putstr.c \
 srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
BINS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

.PHONY: clean fclean re all

all: $(NAME)

$(BINS):
	@gcc -Wall -Werror -Wextra -c FUNCTIONS -I $(INCLUDES)

$(NAME): $(BINS)
	@ar rc $(NAME) $(BINS);

clean:
	@rm -f $(BINS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
