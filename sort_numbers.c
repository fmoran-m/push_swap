#include "push_swap.h"

static int	get_max_position(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->pos > max)
			max = stack->pos;
		stack = stack->next;
	}
	return (max);
}

static void	sort_three(t_stack **stack)
{
	t_stack	*next;
	t_stack *head;
	int		max;

	head = *stack;
	max = get_max_position(*stack);
	*stack = head;
	next = (*stack)->next;
	if ((*stack)->pos == max)
	{
		ra(stack, PRINT);
		sort_three(stack);
	}
	else if (next->pos == max)
	{
		rra(stack, PRINT);
		sort_three(stack);
	}
	else 
	{
		if ((*stack)->pos > next->pos)
			sa(stack, PRINT);
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

static void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		rot;
	int		i;
	int		diff;
	t_stack	*head;

	rot = 0;
	i = 0;
	diff = INT_MAX;
	head = *stack_a;
	while(*stack_a)
	{
		if (((*stack_a)->pos > (*stack_b)->pos)
			&& ((*stack_a)->pos - (*stack_b)->pos) < diff)
		{
			rot = i;
			diff = (*stack_a)->pos - (*stack_b)->pos;
		}
		i++;
		*stack_a = (*stack_a)->next;
	}
	if (diff == INT_MAX)
	{
		*stack_a = head;
		i = 0;
		rot = 0;
		diff = (*stack_a)->pos;
		while(*stack_a)
		{
			if ((*stack_a)->pos < diff)
				rot = i;
			i++;
			*stack_a = (*stack_a)->next;
		}
	}
	*stack_a = head;
	i = 0;
	while(i < rot)
	{
		ra(stack_a, PRINT);
		i++;
	}
	pa(stack_a, stack_b);
}

static void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{

	int		rot;
	int		i;
	int		diff;
	t_stack	*head;

	rot = 0;
	i = 0;
	diff = INT_MIN;
	head = *stack_b;
	while(*stack_b)
	{
		if (((*stack_b)->pos < (*stack_a)->pos)
			&& ((*stack_b)->pos - (*stack_a)->pos) > diff)
		{
			rot = i;
			diff = (*stack_b)->pos - (*stack_a)->pos;
		}
		i++;
		*stack_b = (*stack_b)->next;
	}
	if (diff == INT_MIN)
	{
		*stack_b = head;
		i = 0;
		rot = 0;
		diff = (*stack_b)->pos;
		while(*stack_b)
		{
			if ((*stack_b)->pos > diff)
				rot = i;
			i++;
			*stack_b = (*stack_b)->next;
		}
	}
	*stack_b = head;
	i = 0;
	while(i < rot)
	{
		rb(stack_b, PRINT);
		i++;
	}
	pb(stack_a, stack_b);
}

static t_stack	*turk_algorithm(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	int	current_len;
	int	i;

	current_len = stack_len - 2;
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	while(current_len > 3)
	{
		push_a_to_b(&stack_a, &stack_b);
		current_len--;
	}
	while(current_len < stack_len)
	{
		push_b_to_a(&stack_a, &stack_b);
		current_len++;
	}
	i = 0;
	while(stack_a->pos != 0)
		rra(&stack_a, PRINT);
	return(stack_a);
}

t_stack	*sort_numbers(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	if (check_sort(stack_a))
		return(stack_a);
	else if (stack_len == 2)
	{
		if (stack_a->pos != 0)
			sa(&stack_a, PRINT);
	}
	else if (stack_len == 3)
		sort_three(&stack_a);
	else if (stack_len == 4)
	{
		pb(&stack_a, &stack_b);
		sort_three(&stack_a);
		push_b_to_a(&stack_a, &stack_b);
		while(stack_a->pos != 0)
			rra(&stack_a, PRINT);
	}
	else if (stack_len == 5)
	{
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		sort_three(&stack_a);
		push_b_to_a(&stack_a, &stack_b);
		push_b_to_a(&stack_a, &stack_b);
		while(stack_a->pos != 0)
			rra(&stack_a, PRINT);
	}
	else
		stack_a = turk_algorithm(stack_a, stack_b, stack_len);
	return(stack_a);
}	