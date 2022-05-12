# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 13:52:58 by tvanbael          #+#    #+#              #
#    Updated: 2022/05/09 10:39:29 by tvanbael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/push_swap.c \
					srcs/parser_init.c \
					srcs/is_sort.c \
					srcs/lst_clear_error.c \
					srcs/algo.c \
					srcs/connerie.c \
					srcs/connerie_write_clear.c \
					connerie/connerie_push.c \
					connerie/connerie_swap.c \
					connerie/connerie_rotate.c \
					connerie/connerie_reverse_rotate.c \					
#					operations/push.c \
#					operations/swap.c \
#					operations/rotate.c \
#					operations/reverse_rotate.c \
#					srcs/ft_sort_three.c \
#					srcs/ft_sort_fourth.c \

OBJS			=	$(SRCS:.c=.o)

BONUS			=	checker/checker.c \
					checker/ft_parse_op.c \

BONUS_OBJS		=	$(BONUS:.c=.o)

GCC 			=	gcc

RM				=	rm -f

FLAGS			=	-Wall -Werror -Wextra -g

NAME			=	push_swap

BONUS_NAME		=	checker

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

bonus:		$(BONUS_OBJS)
			$(GCC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
				

.PHONY:		all clean fclean re