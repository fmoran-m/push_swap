/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:16:57 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/18 22:34:05 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_obj_node(t_stack *stack_a, t_stack *stack_b)
{
	int	diff;

	diff = INT_MIN;
	while(stack_a)
	{
		while(stack_b)
		{
			if ((stack_a->pos > stack_b->pos)
				&& ((stack_b->pos - stack_a->pos) > diff))
			{
				stack_a->obj_node = stack_b->pos;
				diff = stack_b->pos - stack_a->pos;
			}
			stack_b = stack_b->next;
		}
		stack_a = stack_a->next;
	}
	return(stack_a);
}