/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:18:59 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 21:05:09 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "libft/libft.h"
# define PRINT		1
# define NO_PRINT	0
typedef	struct s_stack
{
	int				num;
	int				pos;
	int				movs;
	struct s_stack	*next;
	struct s_stack	*obj_node;
}					t_stack;
void		control_digits(char **numbers);
void		check_repeat(int num, char **numbers, t_stack *stack);
void		check_max_int(long long num, char **numbers, t_stack *stack);
void		check_empty_string(char *argv);
t_stack		*create_stack(char **numbers);
t_stack		*stack_init(char **argv, int argc, int argv_flag);
long long	ft_long_atoi(const char *str);
int			get_stack_len(t_stack *stack);
t_stack		*ft_stnew(int num);
void		ft_stadd_back(t_stack **st, t_stack *new);
t_stack		*ft_stlast(t_stack *st);
void		ft_stadd_front(t_stack **st, t_stack *new);
void		ft_stclear(t_stack **st);
void		ft_stdelone(t_stack *st);
void		free_and_exit(t_stack *stack, char **matrix);
void		free_uncomplete_matrix(char **matrix, int current_ind);
void		sa(t_stack **stack_a, int print_flag);
void		sb(t_stack **stack_b, int print_flag);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a, int print_flag);
void		rb(t_stack **stack_b, int print_flag);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a, int print_flag);
void		rrb(t_stack **stack_b, int print_flag);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		exit_gnl(t_stack **stack_a, t_stack **stack_b, char *str);
void		apply_input(char *str, t_stack **stack_a, t_stack **stack_b);
int			control_argc(int argc);
int			check_sort(t_stack *stack);

#endif