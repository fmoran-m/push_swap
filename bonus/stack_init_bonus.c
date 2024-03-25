/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:35:43 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 19:16:53 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
	while (numbers[i])
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

static char	**res_mem(char **argv, int argc)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = malloc(argc * sizeof(char *));
	if (!matrix)
		free_and_exit(NULL, NULL);
	while (i < argc - 1)
	{
		matrix[i] = ft_calloc(ft_strlen(argv[i + 1]) + 1, sizeof(char));
		if (!matrix[i])
			free_uncomplete_matrix(matrix, i);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

static char	**allocate_matrix(char **argv, int argc)
{
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	matrix = res_mem(argv, argc);
	while (matrix[i])
	{
		j = 0;
		while (argv[i + 1][j])
		{
			matrix[i][j] = argv[i + 1][j];
			j++;
		}
		i++;
	}
	return (matrix);
}

static void	check_all_empty(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		check_empty_string(argv[i]);
		i++;
	}
}

t_stack	*stack_init(char **argv, int argc, int argv_flag)
{
	char	**numbers;
	t_stack	*stack_a;

	if (argv_flag)
	{
		check_empty_string(argv[1]);
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			free_and_exit(NULL, NULL);
	}
	else
	{
		check_all_empty(argv, argc);
		numbers = allocate_matrix(argv, argc);
	}
	control_digits(numbers);
	stack_a = create_stack(numbers);
	ft_free_matrix(numbers);
	return (stack_a);
}
