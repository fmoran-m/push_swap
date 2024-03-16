# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 16:57:26 by fmoran-m          #+#    #+#              #
#    Updated: 2024/03/13 19:38:15 by fmoran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

CC = cc

LM = make bonus -C

#CFLAGS = -Wall -Wextra -Werror

INCLUDES = push_swap.h

RM = rm -f

SRC = main.c stack_init.c stack_functions.c push_swap_utils.c push_swap_functions.c push_swap_functions_2.c sort_numbers.c sort_array.c add_index.c

OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS) $(INCLUDES)
		$(LM) $(LIBFTDIR)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY = all clean fclean re bonus
