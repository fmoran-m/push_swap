/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:25:44 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/26 16:25:46 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	both_below_median(t_movs movs)
{
	while (movs.movs_a > 0 && movs.movs_b > 0)
	{
		movs.movs_a--;
		movs.movs_b--;
		movs.total_movs--;
	}
	return (movs.total_movs);
}

int	both_above_median(t_movs movs)
{
	movs.med_movs_a = movs.stack_len_a - movs.movs_a;
	movs.med_movs_b = movs.stack_len_b - movs.movs_b;
	movs.total_movs = movs.med_movs_a + movs.med_movs_b;
	while (movs.movs_a < movs.stack_len_a && movs.movs_b < movs.stack_len_b)
	{
		movs.movs_a++;
		movs.movs_b++;
		movs.total_movs--;
	}
	return (movs.total_movs);
}

int	a_above_median(t_movs movs)
{
	movs.med_movs_a = movs.stack_len_a - movs.movs_a;
	movs.total_movs = movs.med_movs_a + movs.movs_b;
	return (movs.total_movs);
}

int	b_above_median(t_movs movs)
{
	movs.med_movs_b = movs.stack_len_b - movs.movs_b;
	movs.total_movs = movs.med_movs_b + movs.movs_a;
	return (movs.total_movs);
}
