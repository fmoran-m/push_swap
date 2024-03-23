/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:19:00 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:05:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	control_argc(int argc)
{
	if (argc < 2)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	else if (argc == 2)
		return(1);
	else
		return(0);
}

/*
static void	print_stack(t_stack *stack_a)
{
	while(stack_a)
	{
		printf("Number: %d, index: %d\n", stack_a->num, stack_a->pos);
		stack_a = stack_a->next;
	}
}
*/

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_len;
	int		argv_flag;

	argv_flag = control_argc(argc);
	stack_a = stack_init(argv, argc, argv_flag);
	stack_b = NULL;
	stack_len = get_stack_len(stack_a);
	if (get_stack_len(stack_a) > 1)
		stack_a = add_index(stack_a, stack_len);
	stack_a = sort_numbers(stack_a, stack_b, stack_len);
	ft_stclear(&stack_a);
	ft_stclear(&stack_b);
	return (0);
}
