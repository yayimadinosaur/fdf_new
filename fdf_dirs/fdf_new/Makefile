# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfung <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/11 14:50:44 by wfung             #+#    #+#              #
#    Updated: 2018/04/22 18:20:56 by wfung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

SRCS	=	main.c\
			parse_fdf.c\
			create_struct.c\
			store.c\

OBJ =		${SRCS:.c=.o}

INCLUDE	=	-I fdf.h -L ./libft -lft -L ./minilibx_macos -lmlx\
			-framework OpenGL -framework AppKit\

all: $(NAME)

$(OBJ):
		@$(CC) $(FLAG) -c $(SRCS)

$(NAME): $(OBJ)
		@make all -C libft
		@make all -C minilibx_macos
		@$(CC) $(FLAG) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
		@make clean -C libft
		@make clean -C minilibx_macos
		@/bin/rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
