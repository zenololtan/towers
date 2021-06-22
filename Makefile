# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: zenotan <zenotan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/22 17:50:23 by zenotan       #+#    #+#                  #
#    Updated: 2021/06/22 17:50:24 by zenotan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = towers

OBJ_DIR = obj

SRC = main.c \
			utils.c \
			parser.c \
			checkers.c \
			solver.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
