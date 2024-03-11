/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:39:01 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/11 19:26:13 by fmoran-m         ###   ########.fr       */
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
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	check_repeat(int num, t_stack *head)
{
	while(head)
	{
		if (num == head->num)
		{
			ft_putendl_fd("Error", 2);
			exit(1); //LIBERAR!
		}
		head = head->next;
	}
}

static void	check_max_int(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

static t_stack	*create_stack(char **numbers)
{
	int			i;
	long long	num;
	t_stack	*node;
	t_stack	*head;

	i = 0;
	num = ft_long_atoi(numbers[i]);
	node = ft_stnew(num);
	check_max_int(num);
	if (!node)
	{
		ft_free_matrix(numbers);
		exit(1);
	}
	head = node;
	i++;
	while(numbers[i])
	{
		num = ft_long_atoi(numbers[i]);
		check_max_int(num);
		check_repeat(num, head);
		node = ft_stnew(num);
		ft_stadd_back(&head, node);
		i++;
	}
	return (head);
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
