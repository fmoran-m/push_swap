/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_to_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:38:36 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:05:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*next;
	t_stack *head;
	int		max;

	head = *stack;
	max = get_max_position(*stack);
	*stack = head;
	next = (*stack)->next;
	if ((*stack)->pos == max)
	{
		ra(stack, PRINT);
		sort_three(stack);
	}
	else if (next->pos == max)
	{
		rra(stack, PRINT);
		sort_three(stack);
	}
	else 
	{
		if ((*stack)->pos > next->pos)
			sa(stack, PRINT);
	}
}

t_stack *sort_two_to_four(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	if (check_sort(stack_a))
		return(stack_a);
	if (stack_len == 2)
	{
		if (stack_a->pos != 0)
			sa(&stack_a, PRINT);
	}
	else if (stack_len == 3)
		sort_three(&stack_a);
	else if (stack_len == 4)
	{
		pb(&stack_a, &stack_b);
		sort_three(&stack_a);
		push_b_to_a(&stack_a, &stack_b);
		while(stack_a->pos != 0)
			rra(&stack_a, PRINT);
	}
	return (stack_a);
}