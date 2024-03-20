/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:39:01 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/20 21:34:41 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **numbers)
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
