# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 10:54:06 by tvanbael          #+#    #+#              #
#    Updated: 2022/04/28 08:51:29 by tvanbael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERVER		=	srcs/server.c
OBJS_SERVER		=	$(SRCS_SERVER:.c=.o)

SRCS_CLIENT		=	srcs/client.c
OBJS_CLIENT		=	$(SRCS_CLIENT:.c=.o)

SRCS_ADD		= 	
OBJS_ADD		=	$(SRCS_ADD:.c=.o)


GCC 			=	gcc

RM				=	rm -f

FLAGS			=	-Wall -Werror -Wextra -g

NAME_CLIENT		= client
NAME			= server

LIBFT			= libft.a

.c.o:
		@$(GCC) $(FLAGS) -c -I./includes $< -o ${<:.c=.o}

$(NAME):	$(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_ADD)
				@echo '\033[1;36mcompilation of additional component!';
				@$(MAKE) -C ./includes/libft/
				@echo '\033[0;32m-compilation of Libft Complete!';
				@echo '\033[1;36mMoving File libft.a in Folder Root!';
				@cp includes/libft/libft.a .
				@$(GCC) $(FLAGS) $(OBJS_SERVER) $(LIBFT) $(OBJS_ADD) -o $(NAME)
				@echo '\033[0;32mServer Compilation Complete!';
				@$(RM) /srcs/ $(OBJS_SERVER)
				@$(GCC) $(FLAGS) $(OBJS_CLIENT) $(LIBFT) $(OBJS_ADD) -o $(NAME_CLIENT)
				@$(RM) /srcs/ $(OBJS_CLIENT) 
				@echo '\033[0;32mClient Compilation Complete!';

all:		$(NAME)

clean:
			@$(RM) $(OBJS_SERVER)
			@$(RM) $(OBJS_CLIENT)
			@$(RM) $(OBJS_ADD)
			@$(MAKE) clean -C ./includes/libft
			@echo '\033[0;32mClean Complete!';

fclean:		clean
			@$(RM) $(NAME_CLIENT) $(NAME)
			@$(RM) $(LIBFT)
			@$(MAKE) fclean -C ./includes/libft
			@echo '\033[0;32mFullClean Complete!';

re:			fclean all
			@echo '\033[0;32mMake-Re Complete!';

.PHONY:		all clean fclean re