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

static void	check_input(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp("sa\n", str))
		sa(stack_a, NO_PRINT);
	else if (ft_strcmp("sb\n", str))
		sb(stack_b, NO_PRINT);
	else if (ft_strcmp("ss\n", str))
		ss(stack_a, stack_b);
	else if (ft_strcmp("pa\n", str))
		pa(stack_a, stack_b);
	else if (ft_strcmp("pb\n", str))
		pb(stack_a, stack_b);
	else if (ft_strcmp("ra\n"))
		ra(stack_a, NO_PRINT);
	else if (ft_strcmp("rb\n"))
		rb(stack_b, NO_PRINT);
	else if (ft_strcmp("rr\n"))
		rr(stack_a, stack_b);
	else if (ft_strcmp("rra\n"))
		rra(stack_a, NO_PRINT);
	else if(ft_strcmp(stack_b, NO_PRINT))
		rrb(stack_a, NO_PRINT);
	else if(ft_strcmp(stack_a, stack_b))
		rrr(stack_a, stack_b);
	else
		exit(1);//LIBERAR
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;
	int		argv_flag;

	argv_flag = control_argc(argc);
	stack_a = stack_init(argv, argc, argv_flag);
	stack_b = NULL;
	while(1)
	{
		str = get_next_line(0);
		check_input(str, &stack_a, &stack_b);
		free(str);
	}
	return (0);
}
