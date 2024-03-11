/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:38:51 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/11 19:13:09 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stnew(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->next = 0;
	return (new);
}

void	ft_stadd_back(t_stack **st, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	temp = *st;
	if (*st == NULL)
		*st = new;
	else
	{
		temp = ft_stlast(*st);
		temp->next = new;
	}
}

t_stack	*ft_stlast(t_stack *st)
{
	if (!st)
		return (NULL);
	while (st->next != 0)
		st = st->next;
	return (st);
}

void	ft_stadd_front(t_stack **st, t_stack *new)
{
	if (!new || !st)
		return ;
	new->next = *st;
	*st = new;
}
