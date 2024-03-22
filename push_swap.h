/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:07:12 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/22 22:31:47 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define PRINT		1
# define NO_PRINT	0
# include "libft/libft.h"
typedef struct s_stack
{
	int				num;
	int				pos;
	int				movs;
	struct s_stack	*next;
	struct s_stack	*obj_node;
}				t_stack;
typedef struct s_movs
{
	int		total_movs;
	int		stack_len_a;
	int		stack_len_b;
	int		med_movs_a;
	int		med_movs_b;
	int		rev_flag_a;
	int		rev_flag_b;
	int		movs_a;
	int		movs_b;
	float	med_a;
	float	med_b;
}				t_movs;
t_stack		*stack_init(char *argv, int argv_flag);
t_stack		*ft_stnew(int content);
t_stack		*ft_stlast(t_stack *st);
void		ft_stadd_back(t_stack **st, t_stack *new);
void		ft_stadd_front(t_stack **st, t_stack *new);
long long	ft_long_atoi(const char *str);
void		ft_stclear(t_stack **st);
void		ft_stdelone(t_stack *st);
void		sa(t_stack **stack_a, int print_flag);
void		sb(t_stack **stack_b, int print_flag);
void		ss(t_stack **stack_a, t_stack **b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a, int print_flag);
void		rb(t_stack **stack_b, int print_flag);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a, int print_flag);
void		rrb(t_stack **stack_b, int print_flag);
void		rrr(t_stack **stack_a, t_stack **stack_b);
t_stack		*sort_numbers(t_stack *stack_a, t_stack *stack_b, int stack_len);
int			get_stack_len(t_stack *stack);
t_stack		*add_index(t_stack *stack, int stack_len);
t_stack		*sort_two_to_four(t_stack *stack_a, t_stack *stack_b, int stack_len);
void		sort_three(t_stack **stack);
int			get_max_position(t_stack *stack);
t_stack		*turk_algorithm(t_stack *stack_a, t_stack *stack_b, int stack_len);
int			check_sort(t_stack *stack);
void		push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void		push_b_to_a(t_stack **stack_a, t_stack **stack_b);
int			get_min_to_top(t_stack *stack);
void		get_obj_node(t_stack **stack_a, t_stack **stack_b);
void		get_cheaper_num(t_stack **stack_a, t_stack **stack_b);
void		free_and_exit(t_stack *stack, char **matrix);
void		check_empty_string(char *argv);
void		check_max_int(long long num, char **numbers, t_stack *stack);
void		check_repeat(int num, char **numbers, t_stack *stack);
void		control_digits(char **numbers);
t_stack		*create_stack(char **numbers);
int			sort_stack_b(t_stack **stack_a, t_stack **stack_b, int current_len);
int			get_movs(int movs_a, int movs_b, int stack_len_a, int stack_len_b);
t_movs		movs_init(int movs_a, int movs_b, int stack_len_a, int stack_len_b);
int			both_below_median(t_movs movs);
int			both_above_median(t_movs movs);
int			a_above_median(t_movs movs);
int			b_above_median(t_movs movs);
#endif
