# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knarwhal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 18:00:02 by knarwhal          #+#    #+#              #
#    Updated: 2019/10/12 18:53:33 by knarwhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = fillit
# compilation flags
FLAGS = -Wall -Wextra -Werror
# source files
SRCS = $(wildcard proj_fillit/*.c)
# object files
OBJS = $(wildcard proj_fillit/*.o)
# headers
HDRS = $(wildcard proj_fillit/*.h)
# libft
LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(OBJS) $(HDRS)
	make -C libft/ all
	gcc $(FLAGS) -o $(NAME) $(SRCS) $(OBJS) $(LIB)

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
