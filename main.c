/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:19:00 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/13 20:09:04 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	control_argc(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	control_argc(argc);
	stack_a = stack_init(argv[1]);
	stack_b = NULL;
	pa(&stack_a, &stack_b);
	printf("Stack A\n");
	while(stack_a)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	printf("Stack B\n");
	while(stack_b)
	{
		printf("%d\n", stack_b->num);
		stack_b = stack_b->next;
	}
	ft_stclear(&stack_a);
	ft_stclear(&stack_b);
	return (0);
}
