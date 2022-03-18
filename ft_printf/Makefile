# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 13:29:08 by tvanbael          #+#    #+#              #
#    Updated: 2022/03/18 15:53:30 by tvanbael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_printf.c \
			ft_strlen.c \
			ft_itoa.c \
			ft_itoa_unsignd.c \
			ft_putstr.c \
			ft_hexa.c \
			ft_ptr_hexa.c \
			

OBJS	=	$(SRCS:.c=.o)

GCC 	=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Werror -Wextra

NAME	=	libftprintf.a

.c.o:
	$(GCC) $(FLAGS) -c -I. $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			ar rcs $@ $^

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) a.out

re:			fclean all

.PHONY:		all clean fclean re