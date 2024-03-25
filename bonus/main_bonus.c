/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:29:47 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 21:22:22 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_sort(t_stack *stack)
{
	int	temp;

	if (!stack)
		return (0);
	temp = stack->num;
	while (stack)
	{
		if (temp > stack->num)
			return (0);
		temp = stack->num;
		stack = stack->next;
	}
	return (1);
}

int	control_argc(int argc)
{
	if (argc < 2)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	else if (argc == 2)
		return (1);
	else
		return (0);
}

void	apply_input(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp("sa\n", str))
		sa(stack_a, NO_PRINT);
	else if (!ft_strcmp("sb\n", str))
		sb(stack_b, NO_PRINT);
	else if (!ft_strcmp("ss\n", str))
		ss(stack_a, stack_b);
	else if (!ft_strcmp("pa\n", str))
		pa(stack_a, stack_b);
	else if (!ft_strcmp("pb\n", str))
		pb(stack_a, stack_b);
	else if (!ft_strcmp("ra\n", str))
		ra(stack_a, NO_PRINT);
	else if (!ft_strcmp("rb\n", str))
		rb(stack_b, NO_PRINT);
	else if (!ft_strcmp("rr\n", str))
		rr(stack_a, stack_b);
	else if (!ft_strcmp("rra\n", str))
		rra(stack_a, NO_PRINT);
	else if (!ft_strcmp("rrb\n", str))
		rrb(stack_b, NO_PRINT);
	else if (!ft_strcmp("rrr\n", str))
		rrr(stack_a, stack_b);
	else
		exit_gnl(stack_a, stack_b, str);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;
	int		argv_flag;

	argv_flag = control_argc(argc);
	stack_a = stack_init(argv, argc, argv_flag);
	stack_b = NULL;
	str = get_next_line(0);
	while (str)
	{
		apply_input(str, &stack_a, &stack_b);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	if (check_sort(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stclear(&stack_a);
	ft_stclear(&stack_b);
	return (0);
}
