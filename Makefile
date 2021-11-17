# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 15:50:21 by dohykim           #+#    #+#              #
#    Updated: 2021/11/17 03:26:53 by dohykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
CDEBUG	= 	-fsanitize=address -g

FOLDER		=	./srcs/
HEADER		=	./includes/
INSTRUCTION	=	./instr/

SRC_LIST	=	main.c\
				utils.c\
				$(INSTRUCTION)instruction.c\
				$(INSTRUCTION)instruction_utils.c\
				index.c\
				markup.c\
				sort.c\
				solve_a.c\
				solve_b.c\
				command.c\
				direction.c\

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
