/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:37:31 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:05:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **stack_a, int print_flag)
{
	t_stack	*temp;
	t_stack	*temp2;

	if(!*stack_a)
		return;
	if(get_stack_len(*stack_a) <= 1)
		return;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	temp2 = *stack_a;
	while((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = temp;
	*stack_a = temp2;
	if (print_flag == PRINT)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int print_flag)
{
	t_stack	*temp;
	t_stack	*temp2;

	if(!*stack_b)
		return;
	if(get_stack_len(*stack_b) <= 1)
		return;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	temp2 = *stack_b;
	while((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = temp;
	*stack_b = temp2;
	if (print_flag == PRINT)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, NO_PRINT);
	rb(stack_b, NO_PRINT);
	ft_printf("rr\n");
}

void	rra(t_stack **stack_a, int print_flag)
{
	t_stack	*temp;
	t_stack	*head;

	if (!*stack_a)
		return;
	if(get_stack_len(*stack_a) <= 1)
		return;
	head = *stack_a;
	while((*stack_a)->next != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	(*stack_a)->next = head;
	temp->next = NULL;
	if (print_flag == PRINT)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int print_flag)
{
	t_stack	*temp;
	t_stack	*head;

	if (!*stack_b)
		return;
	if(get_stack_len(*stack_b) <= 1)
		return;
	head = *stack_b;
	while((*stack_b)->next != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
	}
	(*stack_b)->next = head;
	temp->next = NULL;
	if (print_flag == PRINT)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, NO_PRINT);
	rrb(stack_b, NO_PRINT);
	ft_printf("rrr\n");
}