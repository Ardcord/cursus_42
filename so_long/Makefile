# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 11:39:14 by tvanbael          #+#    #+#              #
#    Updated: 2022/07/06 17:38:00 by tvanbael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/main.c \
					srcs/open_windows.c \
					srcs/deal_key.c \
					srcs/ft_map.c \
					srcs/ft_load_map.c \
					srcs/error.c \
					srcs/player_move.c \
					srcs/move_true.c \

OBJS			= $(SRCS:.c=.o)

BONUS			=	

BONUS_OBJS		=	$(BONUS:.c=.o)

GCC				=	gcc

RM				=	rm -rf

FLAGS			=	-Wall -Werror -Wextra -Imlx -g3

DANGER			=	-fsanitize=address

NAME			=	so_long

BONUS_NAME		=

LIBFT			=	libft.a

.c.o:
			@$(GCC) $(FLAGS) -c -I./includes $< -o ${<:.c=.o}

MLX				=	-lmlx -framework OpenGL -framework AppKit

$(NAME):	$(OBJS)
				@echo '\033[1;36mcompilation of additional component!';
				@$(MAKE) -C ./includes/mlx
				@echo '\033[0;32m-compilation of Mlx Complete!';
				@$(MAKE) -C ./includes/libft
				@echo '\033[0;32m-compilation of Libft Complete!';
				@echo '\033[1;36mMoving File libft.a & mlx in Folder Root!';
				@cp ./includes/libft/libft.a .
				@cp ./includes/mlx/libmlx.a .
				@$(GCC) $(FLAGS) $(MLX) $(OBJS) $(LIBFT) -o $(NAME)
				@echo '\033[0;32m-so_long created!';

all:		$(NAME)

clean:
			@$(RM) $(OBJS) $(BONUS_OBJS)
				@$(MAKE) clean -C ./includes/mlx
				@$(MAKE) clean -C includes/Libft
				@echo '\033[0;32mClean Complete!';

fclean:		clean
				@$(RM) $(NAME) $(LIBFT) $(BONUS_NAME)
				@$(RM) libmlx.a
				@$(MAKE) clean -C ./includes/mlx
				@$(MAKE) fclean -C ./includes/libft
				@echo '\033[0;32mFullClean Complete!';

re:			fclean all
				@echo '\033[0;32mMake-Re Complete!';

.PHONY:		all clean fclean re
