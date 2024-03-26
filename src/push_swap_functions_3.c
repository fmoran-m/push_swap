/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:24:03 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/26 16:24:07 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, NO_PRINT);
	rb(stack_b, NO_PRINT);
	ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, NO_PRINT);
	rrb(stack_b, NO_PRINT);
	ft_printf("rrr\n");
}
