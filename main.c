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

static int	check_sort(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->num;
	while(stack_a)
	{
		stack_a = stack_a->next;
		if (stack_a->num < temp)
			return(0);
	}
	return (1);
}

static void	sort_three(t_stack **stack)
{
	t_stack *next;

	next = (*stack)->next;
	if ((*stack)->pos == 1 && next->pos == 2)
		rra(stack, PRINT);
	else if ((*stack)->pos == 1 && next->pos == 0)
		sa(stack, PRINT);
	else if ((*stack)->pos == 2 && next->pos == 0)
		ra(stack, PRINT);
	else if ((*stack)->pos == 0 && next->pos == 2)
	{
		rra(stack, PRINT);
		sa(stack, PRINT);
	}
	else if((*stack)->pos == 2 && next->pos == 1)
	{
		sa(stack, PRINT);
		rra(stack, PRINT);
	}
}

static t_stack *sort_numbers(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	if (stack_len == 1)
		return(stack_a);
	if (stack_len == 2)
	{
		if (stack_a->pos != 0)
			sa(&stack_a, PRINT);
		return(stack_a);
	}
	if (stack_len == 3)
		sort_three(&stack_a);
	return (stack_a);
}

static void	print_stack(t_stack *stack_a)
{
	while(stack_a)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
}

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
	stack_a = sort_numbers(stack_a, stack_b, stack_len);
	print_stack(stack_a);
	ft_stclear(&stack_a);
	ft_stclear(&stack_b);
	return (0);
}
