/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:41:22 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/20 19:54:15 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_stack *stack, int stack_len)
{
	int index;
	int	reference;

	index = stack_len - 1;
	reference = stack->num;
	while(stack)
	{
		if (stack->num > reference)
			index--;
		stack = stack->next;
	}
	return (index);
}

t_stack	*add_index(t_stack *stack, int stack_len)
{
	int	counter;

	counter = 0;
	while(counter < stack_len)
	{
		stack->pos = get_index(stack, stack_len);
		ra(&stack, NO_PRINT);
		counter++;
	}
	return (stack);
}