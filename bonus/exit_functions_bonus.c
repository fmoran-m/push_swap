/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:21:35 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:05:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_and_exit(t_stack *stack, char **matrix)
{
	if (stack)
		ft_stclear(&stack);
	if (matrix)
		ft_free_matrix(matrix);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_uncomplete_matrix(char **matrix, int current_ind)
{
	int	i;

	i = 0;
	while (i < current_ind)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	exit_gnl(t_stack **stack_a, t_stack **stack_b, char *str)
{
	close(0);
	get_next_line(0);
	ft_putendl_fd("Error", 2);
	ft_stclear(stack_a);
	ft_stclear(stack_b);
	free(str);
	exit(1);
}
