/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:16:57 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/20 18:27:21 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*get_obj_node(t_stack *stack_a, t_stack *stack_b)
{
	int		diff;
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = stack_a;
	head_b = stack_b;
	while(stack_a)
	{
		diff = INT_MIN;
		stack_b = head_b;
		while(stack_b)
		{
			if ((stack_a->pos > stack_b->pos)
				&& ((stack_b->pos - stack_a->pos) > diff))
			{
				stack_a->obj_node = stack_b;
				diff = stack_b->pos - stack_a->pos;
			}
			stack_b = stack_b->next;
		}
		if (diff == INT_MIN)
			stack_a->obj_node = get_bigger_node(head_b);
		stack_a = stack_a->next;
	}
	return(head_a);
}

static int	get_moves(int moves_a, int moves_b, int stack_len_a, int stack_len_b)
{
	int		total_moves;
	int		med_moves_a;
	int		med_moves_b;
	float	med_a;
	float	med_b;

	med_a = (float)stack_len_a / 2;
	med_b = (float)stack_len_b / 2;
	total_moves = moves_a + moves_b;
	if ((moves_a <= med_a) && (moves_b <= med_b))
	{
		while(moves_a > 0 && moves_b > 0)
		{
			moves_a--;
			moves_b--;
			total_moves--;
		}
		return(total_moves);
	}
	else if ((moves_a > med_a) && (moves_b > med_b))
	{
		med_moves_a = stack_len_a - moves_a;
		med_moves_b = stack_len_b - moves_b;
		total_moves = med_moves_a + med_moves_b;
		while(moves_a < stack_len_a && moves_b < stack_len_b)
		{
			moves_a++;
			moves_b++;
			total_moves--;
		}
		return(total_moves);
	}
	else if(moves_a > med_a)
	{
		med_moves_a = stack_len_a - moves_a;
		total_moves = med_moves_a + moves_b;
		return(total_moves);
	}
	else if(moves_b > med_b)
	{
		med_moves_b = stack_len_b - moves_b;
		total_moves = med_moves_b + moves_a;
		return(total_moves);
	}
	else
		return(total_moves);
}

t_stack *get_cheaper_num(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_len_a;
	int		stack_len_b;
	int		moves_a;
	int		moves_b;
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = stack_a;
	head_b = stack_b;
	stack_len_a = get_stack_len(stack_a);
	stack_len_b = get_stack_len(stack_b);
	moves_a = 0;
	while(stack_a)
	{
		moves_b = 0;
		stack_b = head_b;
		while (stack_a->obj_node != stack_b)
		{
			moves_b++;
			stack_b = stack_b->next;
		}
		stack_a->moves = get_moves(moves_a, moves_b, stack_len_a, stack_len_b);
		moves_a++;
		stack_a = stack_a->next;
	}
	return(head_a);
}