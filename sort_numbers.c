/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:38:11 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/18 22:33:31 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	int	temp;

	temp = 0;
	while(stack)
	{
		if (temp != stack->pos)
			return (0);
		stack = stack->next;
		temp++;
	}
	return (1);
}

t_stack	*turk_algorithm(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	int		current_len;
	int		rot;
	float	med;

	current_len = stack_len - 2;
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	while(current_len > 3)
	{
		stack_a = get_obj_node(stack_a, stack_b);
		stack_a = get_cheaper_num(stack_a, stack_b);
		push_a_to_b(&stack_a, &stack_b);
		current_len--;
	}
	sort_three(&stack_a);
	while(current_len < stack_len)
	{
		push_b_to_a(&stack_a, &stack_b);
		current_len++;
	}
	med = (float)stack_len / 2;
	rot = get_min_to_top(stack_a);
	while(stack_a->pos != 0)
	{
		if (rot <= med)
			ra(&stack_a, PRINT);
		else
			rra(&stack_a, PRINT);
		pa(&stack_a, &stack_b);
	}
	return(stack_a);
}

t_stack	*sort_numbers(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	if (check_sort(stack_a))
		return(stack_a);
	if (stack_len < 5)
		stack_a = sort_two_to_four(stack_a, stack_b, stack_len);
	else
		stack_a = turk_algorithm(stack_a, stack_b, stack_len);
	return(stack_a);
}	