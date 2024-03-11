/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:09:25 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/11 19:28:18 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_long_atoi(const char *str)
{
	long long	acum;
	int	i;
	int	flag;

	acum = 0;
	i = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		acum = acum * 10 + (str[i] - 48);
		i++;
	}
	if (flag == 1)
		acum = acum * -1;
	return (acum);
}