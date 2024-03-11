/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:19:00 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/11 18:20:54 by fmoran-m         ###   ########.fr       */
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
	while(stack_a)
	{
		ft_printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	return (0);
}
