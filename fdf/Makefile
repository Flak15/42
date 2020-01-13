NAME = fdf

FLAGS = -Wall -Wextra -Werror
ATTACH = -L minilibx_macos -lmlx -L./libft -lft -framework OpenGL -framework AppKit 
ATTACH_L = -L./libft -lft -L. -lmlx -L /usr/lib/ -lXext -lX11

SRC = get_next_line.c w_count.c parse.c main.c
OBJ = $(subst .c,.o,$(SRC))


all: $(NAME)

L:
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ATTACH_L)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	rm -f $(OBJ)
	

fclean: clean
	rm -f $(NAME)
	

re: fclean all

