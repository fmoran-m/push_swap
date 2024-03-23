# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 16:57:26 by fmoran-m          #+#    #+#              #
#    Updated: 2024/03/23 20:55:23 by fmoran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

CC = cc

LM = make -C

CFLAGS = -Wall -Wextra -Werror

INCLUDES = push_swap.h

BONUS_INCLUDES = push_swap_bonus.h

RM = rm -f

SRC = src/main.c src/stack_init.c src/stack_functions.c src/push_swap_utils.c src/push_swap_functions.c src/push_swap_functions_2.c src/sort_numbers.c src/add_index.c src/sort_two_to_four.c src/turk_functions.c src/exit_functions.c src/checks.c src/get_movements.c src/possible_movements.c src/push_a_to_b.c src/push_b_to_a.c

OBJS = ${SRC:.c=.o}

BONUS_SRC = bonus/main_bonus.c bonus/checks_bonus.c bonus/push_swap_utils_bonus.c bonus/stack_functions_bonus.c bonus/stack_init_bonus.c bonus/exit_functions_bonus.c bonus/push_swap_functions_2.c bonus/push_swap_bonus_2.c

BONUS_OBJS = ${BONUS_SRC:.c=.o}

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDES)
		$(LM) $(LIBFTDIR)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)

bonus: $(BONUS_OBJS) $(BONUS_INCLUDES)
		$(LM) $(LIBFTDIR)
		$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME_BONUS)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)
		cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY = all clean fclean re bonus
