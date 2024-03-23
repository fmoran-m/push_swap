/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:16:57 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:05:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*get_bigger_node(t_stack *stack_b)
{
	t_stack	*bigger_node;
	int		max;

	bigger_node = stack_b;
	max = stack_b->pos;
	while(stack_b)
	{
		if (stack_b->pos > max)
		{
			bigger_node = stack_b;
			max = stack_b->pos;
		}
		stack_b = stack_b->next;
	}
	return(bigger_node);
}

void	get_obj_node(t_stack **stack_a, t_stack **stack_b)
{
	int		diff;
	t_stack	*head_b;

	head_b = *stack_b;
	while(*stack_a)
	{
		diff = INT_MIN;
		*stack_b = head_b;
		while(*stack_b)
		{
			if (((*stack_a)->pos > (*stack_b)->pos)
				&& (((*stack_b)->pos - (*stack_a)->pos) > diff))
			{
				(*stack_a)->obj_node = *stack_b;
				diff = (*stack_b)->pos - (*stack_a)->pos;
			}
			*stack_b = (*stack_b)->next;
		}
		if (diff == INT_MIN)
			(*stack_a)->obj_node = get_bigger_node(head_b);
		*stack_a = (*stack_a)->next;
	}
}
