/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:48:05 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/18 21:05:50 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		rot;
	int		i;
	int		diff;
	int		stack_len;
	float	med;
	t_stack	*head;

	rot = 0;
	i = 0;
	diff = INT_MAX;
	head = *stack_a;
	while(*stack_a)
	{
		if (((*stack_a)->pos > (*stack_b)->pos)
			&& ((*stack_a)->pos - (*stack_b)->pos) < diff)
		{
			rot = i;
			diff = (*stack_a)->pos - (*stack_b)->pos;
		}
		i++;
		*stack_a = (*stack_a)->next;
	}
	if (diff == INT_MAX)
	{
		*stack_a = head;
		i = 0;
		rot = 0;
		diff = (*stack_a)->pos;
		while(*stack_a)
		{
			if ((*stack_a)->pos < diff)
				rot = i;
			i++;
			*stack_a = (*stack_a)->next;
		}
	}
	*stack_a = head;
	stack_len = get_stack_len(*stack_a);
	*stack_a = head;
	med = (float)stack_len / 2;
	if (rot == 0)
		pa(stack_a, stack_b);
	else if (rot <= med)
	{
		while(rot > 0)
		{
			ra(stack_a, PRINT);
			rot--;
		}
		pa(stack_a, stack_b);
	}
	else
	{
		i = 0;
		while (i < (stack_len - rot))
		{
			rra(stack_a, PRINT);
			i++;
		}
		pa(stack_a, stack_b);
	}
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		rot;
	int		i;
	int		diff;
	int		stack_len;
	float	med;
	t_stack	*head;

	rot = 0;
	i = 0;
	diff = INT_MIN;
	head = *stack_b;
	while(*stack_b)
	{
		if (((*stack_a)->pos > (*stack_b)->pos)
			&& ((*stack_b)->pos - (*stack_a)->pos) > diff)
		{
			rot = i;
			diff = (*stack_b)->pos - (*stack_a)->pos;
		}
		i++;
		*stack_b = (*stack_b)->next;
	}
	if (diff == INT_MIN)
	{
		*stack_b = head;
		i = 0;
		rot = 0;
		diff = (*stack_b)->pos;
		while(*stack_b)
		{
			if ((*stack_b)->pos > diff)
			{
				rot = i;
				diff = (*stack_b)->pos;
			}
			i++;
			*stack_b = (*stack_b)->next;
		}
	}
	*stack_b = head;
	stack_len = get_stack_len(*stack_b);
	*stack_b = head;
	med = (float)stack_len / 2;
	if (rot == 0)
		pb(stack_a, stack_b);
	else if (rot <= med)
	{
		while(rot > 0)
		{
			rb(stack_b, PRINT);
			rot--;
		}
		pb(stack_a, stack_b);
	}
	else
	{
		i = 0;
		while (i < (stack_len - rot))
		{
			rrb(stack_b, PRINT);
			i++;
		}
		pb(stack_a, stack_b);
	}
}