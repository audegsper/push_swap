# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 15:50:21 by dohykim           #+#    #+#              #
#    Updated: 2021/11/21 00:29:51 by dohykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
CDEBUG	= 	-fsanitize=address -g

FOLDER	=	./srcs/
HEADER	=	./includes/
UTILS	=	./utils/
SORT	=	./sort/

SRC_LIST	=	main.c\
				$(UTILS)utils.c\
				$(UTILS)instruction.c\
				$(UTILS)instruction_utils.c\
				$(UTILS)stack_utils.c\
				$(UTILS)command.c\
				$(SORT)index.c\
				$(SORT)solve_a.c\
				$(SORT)solve_b.c\
				$(SORT)direction.c\

SRC		=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJS	=	$(SRC:%.c=%.o)

all	:		$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) $(CDEBUG) -I$(HEADER) -o $@ -c $<

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(CDEBUG) -I$(HEADER) -o $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
