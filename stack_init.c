/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:39:01 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/20 20:47:03 by fmoran-m         ###   ########.fr       */
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
				free_and_exit(NULL, numbers);
			j++;
		}
		i++;
	}
}

static void	check_repeat(int num, char **numbers, t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while(stack)
	{
		if (num == stack->num)
			free_and_exit(head, numbers);
		stack = stack->next;
	}
}

static void	check_max_int(long long num, char **numbers, t_stack *stack)
{
	if (num > INT_MAX || num < INT_MIN)
		free_and_exit(stack, numbers);
}

static void	check_empty_string(char *argv)
{
	int	i;

	if (!*argv)
		free_and_exit(NULL, NULL);
	i = 0;
	while(argv[i] == ' ')
		i++;
	if (argv[i] == 0)
		free_and_exit(NULL, NULL);
}

static t_stack	*create_stack(char **numbers)
{
	long long	num;
	t_stack		*node;
	t_stack		*head;
	int			i;

	i = 0;
	num = ft_long_atoi(numbers[i]);
	node = ft_stnew(num);
	if (!node)
		free_and_exit(NULL, numbers);
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
			free_and_exit(head, numbers);
		ft_stadd_back(&head, node);
		i++;
	}
	return (head);
}

t_stack	*stack_init(char *argv)
{
	char	**numbers;
	t_stack	*stack_a;

	
	check_empty_string(argv);
	numbers = ft_split(argv, ' ');
	if (!numbers)
		free_and_exit(NULL, NULL);
	control_digits(numbers);
	stack_a = create_stack(numbers);
	ft_free_matrix(numbers);
	return(stack_a);
}
