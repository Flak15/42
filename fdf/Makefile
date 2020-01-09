NAME = fdf

FLAGS = -Wall -Wextra -Werror
ATTACH = -L minilibx_macos -lmlx -L./libft -lft -framework OpenGL -framework AppKit 

SRC = main.c
OBJ = $(subst .c,.o,$(SRC))


all: $(NAME)

L:
	gcc -o $(NAME) main.c -L. -lft -lmlx -L /usr/lib/ -lXext -lX11

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	rm -f $(OBJ)
	

fclean: clean
	rm -f $(NAME)
	

re: fclean all

