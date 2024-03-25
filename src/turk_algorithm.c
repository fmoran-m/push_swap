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

t_stack	*turk_algorithm(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	int		current_len;
	int		rot;
	float	med;

	current_len = stack_len - 2;
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	current_len = sort_stack_b(&stack_a, &stack_b, current_len);
	sort_three(&stack_a);
	while(current_len < stack_len)
	{
		push_b_to_a(&stack_a, &stack_b);
		current_len++;
	}
	med = (float)stack_len / 2;
	rot = rots_min_to_top(stack_a);
	while(stack_a->pos != 0)
	{
		if (rot <= med)
			ra(&stack_a, PRINT);
		else
			rra(&stack_a, PRINT);
	}
	return(stack_a);
}

int	sort_stack_b(t_stack **stack_a, t_stack **stack_b, int current_len)
{
	t_stack *head_a;
	t_stack *head_b;

	while(current_len > 3)
	{
		head_a = *stack_a;
		head_b = *stack_b;
		get_target_node(stack_a, stack_b);
		*stack_a = head_a;
		*stack_b = head_b;
		get_cheaper_num(stack_a, stack_b);
		*stack_a = head_a;
		*stack_b = head_b;
		push_a_to_b(stack_a, stack_b);
		current_len--;
	}
	return (current_len);
}

void	get_target_node(t_stack **stack_a, t_stack **stack_b)
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
				(*stack_a)->trg_node = *stack_b;
				diff = (*stack_b)->pos - (*stack_a)->pos;
			}
			*stack_b = (*stack_b)->next;
		}
		if (diff == INT_MIN)
			(*stack_a)->trg_node = get_bigger_node(head_b);
		*stack_a = (*stack_a)->next;
	}
}

t_stack	*get_bigger_node(t_stack *stack_b)
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

int	rots_min_to_top(t_stack *stack)
{
	int	rot;

	rot = 0;
	while (stack->pos != 0)
	{
		stack = stack->next;
		rot++;
	}
	return (rot);
}