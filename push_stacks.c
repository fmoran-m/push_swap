/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:48:05 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/20 18:34:03 by fmoran-m         ###   ########.fr       */
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

t_stack	*get_selected_node(t_stack *stack_a)
{
	t_stack	*selected;

	selected = stack_a;
	while(stack_a)
	{
		if (stack_a->moves < selected->moves)
			selected = stack_a;
		stack_a = stack_a->next;
	}
	return (selected);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*selected;
	t_stack		*head_a;
	t_stack		*head_b;
	int			moves_a;
	int			moves_b;
	int			stack_len_a;
	int			stack_len_b;
	int			rev_flag_a;
	int			rev_flag_b;
	float		med_a;
	float		med_b;

	head_a = *stack_a;
	head_b = *stack_b;
	selected = get_selected_node(*stack_a);
	*stack_a = head_a;
	moves_a = 0;
	moves_b = 0;
	while(*stack_a != selected)
	{
		moves_a++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
	while(*stack_b != selected->obj_node)
	{
		moves_b++;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = head_b;
	stack_len_a = get_stack_len(*stack_a);
	*stack_a = head_a;
	stack_len_b = get_stack_len(*stack_b);
	*stack_b = head_b;
	med_a = (float)stack_len_a / 2;
	med_b = (float)stack_len_b / 2;
	rev_flag_a = 0;
	if (moves_a > med_a)
	{
		rev_flag_a = 1;
		moves_a = stack_len_a - moves_a;
		//printf("%d\n", moves_a);
	}
	rev_flag_b = 0;
	if (moves_b > med_b)
	{
		rev_flag_b = 1;
		moves_b = stack_len_b - moves_b;
	//	printf("%d\n", moves_b);
	}
	//EMPEZAMOS A ROTAR
	while(moves_a > 0 && moves_b > 0)
	{
		if (rev_flag_a && rev_flag_b)
		{
			rrr(stack_a, stack_b);
			moves_a--;
			moves_b--;
		}
		else if (!rev_flag_a && !rev_flag_b)
		{
			rr(stack_a, stack_b);
			moves_a--;
			moves_b--;
		}
		else if (rev_flag_a && !rev_flag_b)
		{
			rra(stack_a, PRINT);
			rb(stack_b, PRINT);
			moves_a--;
			moves_b--;
		}
		else
		{
			ra(stack_a, PRINT);
			rrb(stack_b, PRINT);
			moves_a--;
			moves_b--;
		}
	}
	while(moves_a > 0)
	{
		if (rev_flag_a)
		{
			rra(stack_a, PRINT);
			moves_a--;
		}
		else
		{
			ra(stack_a, PRINT);
			moves_a--;
		}
	}
	while(moves_b > 0)
	{
		if (rev_flag_b)
		{
			rrb(stack_b, PRINT);
			moves_b--;
		}
		else
		{
			rb(stack_b, PRINT);
			moves_b--;
		}
	}
	pb(stack_a, stack_b);
}