/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:26:17 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/26 16:26:18 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_selected_node(t_stack *stack_a)
{
	t_stack	*selected;

	selected = stack_a;
	while (stack_a)
	{
		if (stack_a->movs < selected->movs)
			selected = stack_a;
		stack_a = stack_a->next;
	}
	return (selected);
}

static t_movs	get_push_a_params(t_stack **stack_a, t_stack **stack_b,
		t_stack *selected, t_movs movs)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	movs.movs_a = 0;
	movs.movs_b = 0;
	while (*stack_a != selected)
	{
		movs.movs_a++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
	while (*stack_b != selected->trg_node)
	{
		movs.movs_b++;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = head_b;
	movs.med_a = (float)movs.stack_len_a / 2;
	movs.med_b = (float)movs.stack_len_b / 2;
	movs.rev_flag_a = 0;
	return (movs);
}

static t_movs	define_stack_direction(t_movs movs)
{
	if (movs.movs_a > movs.med_a)
	{
		movs.rev_flag_a = 1;
		movs.movs_a = movs.stack_len_a - movs.movs_a;
	}
	movs.rev_flag_b = 0;
	if (movs.movs_b > movs.med_b)
	{
		movs.rev_flag_b = 1;
		movs.movs_b = movs.stack_len_b - movs.movs_b;
	}
	return (movs);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*selected;
	t_movs	movs;

	movs.stack_len_a = get_stack_len(*stack_a);
	movs.stack_len_b = get_stack_len(*stack_b);
	selected = get_selected_node(*stack_a);
	movs = get_push_a_params(stack_a, stack_b, selected, movs);
	movs = define_stack_direction(movs);
	movs = double_rotations(movs, stack_a, stack_b);
	movs = std_rotations(movs, stack_a, stack_b);
	pb(stack_a, stack_b);
}
