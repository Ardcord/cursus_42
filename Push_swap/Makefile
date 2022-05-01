# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 13:52:58 by tvanbael          #+#    #+#              #
#    Updated: 2022/05/01 20:38:10 by tvanbael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/push_swap.c \
					srcs/parser_init.c \
					srcs/is_sort.c \
					srcs/lst_clear_error.c \
					operations/push.c \
					operations/swap.c \
					operations/reverse_rotate.c \
					operations/rotate.c \

OBJS			=	$(SRCS:.c=.o)

BONUS			=	checker/chercker.c \
					checker/ft_parse_op.c \

BONUS_OBJS		=	$(BONUS:.c=.o)

GCC 			=	gcc

RM				=	rm -f

FLAGS			=	-Wall -Werror -Wextra -g

NAME			=	push_swap

LIBFT			=	libft.a

.c.o:
			@$(GCC) $(FLAGS) -c -I./includes $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
				@echo '\033[1;36mcompilation of additional component!';
				@$(MAKE) -C ./includes/libft/
				@echo '\033[0;32m-compilation of Libft Complete!';
				@echo '\033[1;36mMoving File libft.a in Folder Root!';
				@cp includes/libft/libft.a .
				@$(GCC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
				@$(RM) /srcs/ $(OBJS)
				@echo '\033[0;32mPush_swap Compilation Complete!';

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
				@$(MAKE) clean -C ./includes/libft
				@echo '\033[0;32mClean Complete!';

fclean:		clean
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)
				@$(MAKE) fclean -C ./includes/libft
				@echo '\033[0;32mFullClean Complete!';

re:			fclean all
				@echo '\033[0;32mMake-Re Complete!';

bonus:		$(BONUS) $(BONUS_OBJS)
				ar rcs 
				

.PHONY:		all clean fclean re