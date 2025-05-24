/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:18:30 by fmoran-m          #+#    #+#             */
/*   Updated: 2025/05/24 15:30:40 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_rotations_for_min(t_stack **stack_a)
{
	int		i;
	int		rot;
	int		diff;
	t_stack	*tmp;

	i = 0;
	rot = 0;
	tmp = *stack_a;
	diff = tmp->pos;
	while (tmp)
	{
		if (tmp->pos < diff)
		{
			diff = tmp->pos;
			rot = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (rot);
}

static int	get_rotations(t_stack **stack_a, t_stack **stack_b)
{
	int		rot;
	int		i;
	int		diff;
	t_stack	*head;

	rot = 0;
	i = 0;
	diff = INT_MAX;
	head = *stack_a;
	while (*stack_a)
	{
		if (((*stack_a)->pos > (*stack_b)->pos) && ((*stack_a)->pos
				- (*stack_b)->pos) < diff)
		{
			rot = i;
			diff = (*stack_a)->pos - (*stack_b)->pos;
		}
		i++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head;
	if (diff == INT_MAX)
		rot = get_rotations_for_min(stack_a);
	return (rot);
}

static void	rotate_below_med(t_stack **stack_a, t_stack **stack_b, int rot)
{
	while (rot > 0)
	{
		ra(stack_a, PRINT);
		rot--;
	}
	pa(stack_a, stack_b);
}

static void	rotate_above_med(t_stack **stack_a, t_stack **stack_b, int rot,
		int stack_len)
{
	int	i;

	i = 0;
	while (i < (stack_len - rot))
	{
		rra(stack_a, PRINT);
		i++;
	}
	pa(stack_a, stack_b);
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		rot;
	int		stack_len;
	float	med;
	t_stack	*head;

	head = *stack_a;
	rot = get_rotations(stack_a, stack_b);
	*stack_a = head;
	stack_len = get_stack_len(*stack_a);
	med = (float)stack_len / 2;
	if (rot == 0)
		pa(stack_a, stack_b);
	else if (rot <= med)
		rotate_below_med(stack_a, stack_b, rot);
	else
		rotate_above_med(stack_a, stack_b, rot, stack_len);
}
