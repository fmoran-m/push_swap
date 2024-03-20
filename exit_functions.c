/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:21:35 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/20 21:24:26 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_stack *stack, char **matrix)
{
	if (stack)
		ft_stclear(&stack);
	if (matrix)
		ft_free_matrix(matrix);
	ft_putendl_fd("Error", 2);
	exit(1);
}