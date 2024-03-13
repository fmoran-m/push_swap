/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:37:31 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/13 19:15:30 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	temp2 = *stack_a;
	while((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = temp;
	*stack_a = temp2;
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	temp2 = *stack_b;
	while((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = temp;
	*stack_b = temp2;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*head;
	t_stack	*new;

	head = *stack_a;
	while((*stack_a)->next != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	(*stack_a)->next = head;
	temp->next = NULL;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*head;
	t_stack	*new;

	head = *stack_b;
	while((*stack_b)->next != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
	}
	(*stack_b)->next = head;
	temp->next = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}