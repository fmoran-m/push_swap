/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:07:12 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/11 20:34:19 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;
t_stack		*stack_init(char *argv);
t_stack		*ft_stnew(int content);
t_stack		*ft_stlast(t_stack *st);
void		ft_stadd_back(t_stack **st, t_stack *new);
void		ft_stadd_front(t_stack **st, t_stack *new);
long long	ft_long_atoi(const char *str);
void		ft_stclear(t_stack **st);
void		ft_stdelone(t_stack *st);
#endif
