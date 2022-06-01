# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 13:52:58 by tvanbael          #+#    #+#              #
#    Updated: 2022/05/31 11:36:20 by tvanbael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/push_swap.c \
					srcs/parser_init.c \
					srcs/is_sort.c \
					srcs/algo.c \
					srcs/brut.c	\
					srcs/connerie.c \
					srcs/connerie_write_clear.c \
					srcs/ope_try_push.c \
					srcs/ope_try_swap.c \
					srcs/ope_try_rotate.c \
					srcs/ope_try_reverse.c \
					srcs/ft_try_only_swap.c \
					srcs/ft_try_next_push_swap.c \
					srcs/ft_try_next_rotate.c \
					srcs/ft_try_next_reverse.c \
					srcs/ft_reverse_retry.c \
					srcs/ft_pars_howsort.c \
					srcs/ft_quick.c \
					srcs/ft_method_ab.c \
					srcs/ft_how_sort.c \
					srcs/ft_how_rotate.c \
					srcs/ft_min_and_ini.c \
					operations/push.c \
					operations/swap.c \
					operations/rotate.c \
					operations/reverse_rotate.c \

OBJS			=	$(SRCS:.c=.o)

BONUS			=	checker_d/checker.c \
					checker_d/lst_clear_error.c \
					checker_d/ft_parse_op.c \
					srcs/is_sort.c \
					srcs/parser_init.c \
					operations/push.c \
					operations/swap.c \
					operations/rotate.c \
					operations/reverse_rotate.c \

BONUS_OBJS		=	$(BONUS:.c=.o)

GCC 			=	gcc

RM				=	rm -f

FLAGS			=	-Wall -Werror -Wextra -g3

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
				@echo '\033[0;32mPush_swap Compilation Complete!';

all:		$(NAME)

clean:
			@$(RM) $(OBJS) $(BONUS_OBJS)
				@$(MAKE) clean -C ./includes/libft
				@echo '\033[0;32mClean Complete!';

fclean:		clean
				@$(RM) $(NAME) $(LIBFT) $(BONUS_NAME)
				@$(MAKE) fclean -C ./includes/libft
				@echo '\033[0;32mFullClean Complete!';

re:			fclean all
				@echo '\033[0;32mMake-Re Complete!';

$(BONUS_NAME):		$(BONUS_OBJS)
				@$(MAKE) -C ./includes/libft/
				@echo '\033[0;32mCompilation of Libft Complete!';
				@cp includes/libft/libft.a .
				@$(GCC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
				@echo '\033[0;32mChecker Compilation Complete!';
				
bonus:		$(BONUS_NAME)

.PHONY:		all clean fclean re
