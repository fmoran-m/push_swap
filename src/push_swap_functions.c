/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:36:40 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:05:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stack_a, int print_flag)
{
	t_stack	*temp;
	t_stack *temp2;

	if (!*stack_a)
		return;
	if(get_stack_len(*stack_a) <= 1)
		return;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp2 = (*stack_a)->next;
	temp->next = temp2;
	(*stack_a)->next = temp;
	if (print_flag == PRINT)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, int print_flag)
{
	t_stack	*temp;
	t_stack *temp2;

	if (!*stack_b)
		return;
	if(get_stack_len(*stack_b) <= 1)
		return;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp2 = (*stack_b)->next;
	temp->next = temp2;
	(*stack_b)->next = temp;
	if (print_flag == PRINT)
		ft_printf("sa\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, NO_PRINT);
	sb(stack_b, NO_PRINT);
	ft_printf("ss\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!*stack_a)
		return;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
	ft_printf("pb\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!*stack_b)
		return;
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = temp;
	ft_printf("pa\n");
}