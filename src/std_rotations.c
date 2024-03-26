/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:27:01 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/26 16:27:03 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_movs	rot_stack_a_updt_movs(t_movs movs, t_stack **stack_a)
{
	if (movs.rev_flag_a)
	{
		rra(stack_a, PRINT);
		movs.movs_a--;
	}
	else
	{
		ra(stack_a, PRINT);
		movs.movs_a--;
	}
	return (movs);
}

static t_movs	rot_stack_b_updt_movs(t_movs movs, t_stack **stack_b)
{
	if (movs.rev_flag_b)
	{
		rrb(stack_b, PRINT);
		movs.movs_b--;
	}
	else
	{
		rb(stack_b, PRINT);
		movs.movs_b--;
	}
	return (movs);
}

t_movs	std_rotations(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	while (movs.movs_a > 0)
		movs = rot_stack_a_updt_movs(movs, stack_a);
	while (movs.movs_b > 0)
		movs = rot_stack_b_updt_movs(movs, stack_b);
	return (movs);
}
