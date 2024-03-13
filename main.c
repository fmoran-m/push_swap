/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:19:00 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/03/13 22:32:34 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	control_argc(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

static int	get_stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	h;
	int	aux;

	i = 0;
	h = 1;
	while (h <= size - 1)
	{
		if (tab[i] > tab[h])
		{
			aux = tab[i];
			tab[i] = tab[h];
			tab[h] = aux;
			i = 0;
			h = 1;
		}
		else
		{
			i++;
			h++;
		}
	}
}

static int	*bubblesort(t_stack *stack_a, int stack_len)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(stack_len * sizeof(int));
	while (i < stack_len)
	{
		array[i] = stack_a->num;
		stack_a = stack_a->next;
		i++;
	}
	ft_sort_int_tab(array, stack_len);
	return (array);
}

static int	get_index(int num, int *array)
{
	int	i;

	i = 0;
	while(num != array[i])
		i++;
	return (i);
}

static t_stack	*add_index(t_stack *stack, int *aux_array)
{
	t_stack *head;

	head = stack;
	while(stack)
	{
		stack->pos = get_index(stack->num, aux_array);
		stack = stack->next;
	}
	return (head);
}
/*
static void	check_order(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	int	diff;
	int	prev_pos;

	diff = 1;
	prev_pos = stack_a->pos;
	stack_a = stack_a->next;
	while(stack_a)
	{
		diff = stack_a->num - prev_pos;
		if (diff != 1)
			break;
		prev_pos = stack_a->pos;
		stack_a = stack_a->next;
	}
	if (diff == 1)
		return (1);
	else
		return (0);
}
*/
int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*aux_array;
	int		stack_len;

	control_argc(argc);
	stack_a = stack_init(argv[1]);
	stack_b = NULL;
	stack_len = get_stack_len(stack_a);
	aux_array = bubblesort(stack_a, stack_len);
	stack_a = add_index(stack_a, aux_array);
	free(aux_array);
	int	i = 0;
	while(stack_a)
	{
		if (stack_a->pos != i)
			ra(&stack_a, PRINT);
		else 
		{
			pb(&stack_a, &stack_b);
			i++;
		}
	}
	i = 0;
	while(i < stack_len)
	{
		pa(&stack_a, &stack_b);
		i++;
	}
	while(stack_a)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_stclear(&stack_a);
	ft_stclear(&stack_b);
	return (0);
}
