/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:35:25 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 21:06:15 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	control_digits(char **numbers)
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

void	check_repeat(int num, char **numbers, t_stack *stack)
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

void	check_max_int(long long num, char **numbers, t_stack *stack)
{
	if (num > INT_MAX || num < INT_MIN)
		free_and_exit(stack, numbers);
}

void	check_empty_string(char *argv)
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