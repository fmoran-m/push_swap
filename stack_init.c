/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:39:01 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/12 17:48:50 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	control_digits(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while(numbers[i])
	{
		j = 0;
		if (numbers[i][j] == '-')
			j++;
		while(numbers[i][j])
		{
			if (!ft_isdigit(numbers[i][j]))
			{
				ft_putendl_fd("Error", 2);
				ft_free_matrix(numbers);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	check_repeat(int num, char **numbers, t_stack *stack)
{
	while(stack)
	{
		if (num == stack->num)
		{
			ft_putendl_fd("Error", 2);
			ft_free_matrix(numbers);
			ft_stclear(&stack);
			exit(1);
		}
		stack = stack->next;
	}
}

static int	check_max_int(long long num, char **numbers, t_stack *stack)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putendl_fd("Error", 2);
		ft_free_matrix(numbers);
		ft_stclear(&stack);
		return (0);
	}
	else
		return (1);
}

static void	check_empty_string(char *argv)
{
	int	i;

	i = 0;
	while(argv[i] == ' ')
		i++;
	if (argv[i] == 0)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

static t_stack	*create_stack(char **numbers)
{
	int			i;
	long long	num;
	t_stack		*node;
	t_stack		*head;

	i = 0;
	num = ft_long_atoi(numbers[i]);
	node = ft_stnew(num);
	if (!node)
	{
		ft_free_matrix(numbers);
		exit(1);
	}
	check_max_int(num, numbers, node);
	head = node;
	i++;
	while(numbers[i])
	{
		num = ft_long_atoi(numbers[i]);
		check_max_int(num, numbers, head);
		check_repeat(num, numbers, head);
		node = ft_stnew(num);
		if (!node)
		{
			ft_putendl_fd("Error", 2);
			ft_free_matrix(numbers);
			ft_stclear(&head);
			exit(1);
		}
		ft_stadd_back(&head, node);
		i++;
	}
	return (head);
}

t_stack	*stack_init(char *argv)
{
	char	**numbers;
	t_stack	*stack_a;

	if (!*argv)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	check_empty_string(argv);
	numbers = ft_split(argv, ' ');
	if (!numbers)
		exit(1);
	control_digits(numbers);
	stack_a = create_stack(numbers);
	ft_free_matrix(numbers);
	return(stack_a);
}
