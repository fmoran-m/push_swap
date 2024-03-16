#include "push_swap.h"


static void	sort_rel_three(t_stack **stack)
{
	t_stack *next;

	next = (*stack)->next;
	if ((*stack)->rel == 1 && next->rel == 2)
		rra(stack, PRINT);
	else if ((*stack)->rel == 1 && next->rel == 0)
		sa(stack, PRINT);
	else if ((*stack)->rel == 2 && next->rel == 0)
		ra(stack, PRINT);
	else if ((*stack)->rel == 0 && next->rel == 2)
	{
		rra(stack, PRINT);
		sa(stack, PRINT);
	}
	else if((*stack)->rel == 2 && next->rel == 1)
	{
		sa(stack, PRINT);
		rra(stack, PRINT);
	}
}

static int	get_rel_index(t_stack *stack_a)
{
	int	num;
	int	rel_index;

	num = stack_a->num;
	rel_index = 2;
	while(stack_a)
	{
		if (stack_a->num > num)
			rel_index--;
		stack_a = stack_a->next;
	}
	return (rel_index);
}

static t_stack	*add_rel_index(t_stack *stack_a, int stack_len)
{
	int	i;

	i = 0;
	while(i < stack_len)
	{
		stack_a->rel = get_rel_index(stack_a);
		rra(&stack_a, NO_PRINT);
		i++;
	}
	rra(&stack_a, NO_PRINT);
	return(stack_a);
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

static int	check_sort(t_stack *stack)
{
	int	temp;

	temp = 0;
	while(stack)
	{
		if (temp != stack->pos)
			return (0);
		stack = stack->next;
		temp++;
	}
	return (1);
}

t_stack	*sort_numbers(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	if (check_sort(stack_a))
		return(stack_a);
	if (stack_len == 2)
	{
		if (stack_a->pos != 0)
			sa(&stack_a, PRINT);
		return(stack_a);
	}
	if (stack_len == 3)
	{
		sort_three(&stack_a);
		return(stack_a);
	}
	if (stack_len == 4)
	{
		pb(&stack_a, &stack_b);
		stack_a = add_rel_index(stack_a, stack_len);
		sort_rel_three(&stack_a);
		while(stack_a->pos != stack_b->pos + 1)
			ra(&stack_a, PRINT);
		pa(&stack_a, &stack_b);
		while(stack_a->pos != 0)
			ra(&stack_a, PRINT);
	}
	return(stack_a);
}	