#include "push_swap.h"

t_stack	*get_selected_node(t_stack *stack_a)
{
	t_stack	*selected;

	selected = stack_a;
	while(stack_a)
	{
		if (stack_a->movs < selected->movs)
			selected = stack_a;
		stack_a = stack_a->next;
	}
	return (selected);
}

static t_movs	get_push_a_params(t_stack **stack_a, t_stack **stack_b, t_stack *selected, t_movs movs)
{
	t_stack		*head_a;
	t_stack		*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	movs.movs_a = 0;
	movs.movs_b = 0;
	while(*stack_a != selected)
	{
		movs.movs_a++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
	while(*stack_b != selected->obj_node)
	{
		movs.movs_b++;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = head_b;
	movs.med_a = (float)movs.stack_len_a / 2;
	movs.med_b = (float)movs.stack_len_b / 2;
	movs.rev_flag_a = 0;
	return(movs);
}

static t_movs	define_stack_direction(t_movs movs)
{
	if (movs.movs_a > movs.med_a)
	{
		movs.rev_flag_a = 1;
		movs.movs_a = movs.stack_len_a - movs.movs_a;
	}
	movs.rev_flag_b = 0;
	if (movs.movs_b > movs.med_b)
	{
		movs.rev_flag_b = 1;
		movs.movs_b = movs.stack_len_b - movs.movs_b;
	}
	return(movs);
}

static t_movs	rrr_updt_movs(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	rrr(stack_a, stack_b);
	movs.movs_a--;
	movs.movs_b--;
	return(movs);
}

static t_movs	rr_updt_movs(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	rr(stack_a, stack_b);
	movs.movs_a--;
	movs.movs_b--;
	return (movs);
}

static t_movs	rra_rb_updt_movs(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, PRINT);
	rb(stack_b, PRINT);
	movs.movs_a--;
	movs.movs_b--;
	return(movs);
}

static t_movs	ra_rrb_updt_movs(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, PRINT);
	rrb(stack_b, PRINT);
	movs.movs_a--;
	movs.movs_b--;
	return(movs);
}

static t_movs	double_rotations(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	while(movs.movs_a > 0 && movs.movs_b > 0)
	{
		if (movs.rev_flag_a && movs.rev_flag_b)
			movs = rrr_updt_movs(movs, stack_a, stack_b);
		else if (!movs.rev_flag_a && !movs.rev_flag_b)
			movs = rr_updt_movs(movs, stack_a, stack_b);
		else if (movs.rev_flag_a && !movs.rev_flag_b)
			movs = rra_rb_updt_movs(movs, stack_a, stack_b);
		else
			movs = ra_rrb_updt_movs(movs, stack_a, stack_b);
	}
	return(movs);
}

static t_movs	rot_stack_a_updt_movs(t_movs movs, t_stack **stack_a)
{
	if (movs.rev_flag_a)
	{
		rra(stack_a, PRINT);
		movs.movs_a--;
	}
	else
	{
		ra(stack_a, PRINT);
		movs.movs_a--;
	}
	return (movs);
}

static t_movs	rot_stack_b_updt_movs(t_movs movs, t_stack **stack_b)
{
	if (movs.rev_flag_b)
	{
		rrb(stack_b, PRINT);
		movs.movs_b--;
	}
	else
	{
		rb(stack_b, PRINT);
		movs.movs_b--;
	}
	return (movs);
}

static t_movs	std_rotations(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	while(movs.movs_a > 0)
		movs = rot_stack_a_updt_movs(movs, stack_a);
	while(movs.movs_b > 0)
		movs = rot_stack_b_updt_movs(movs, stack_b);
	return(movs);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*selected;
	t_stack		*head_a;
	t_stack		*head_b;
	t_movs		movs;

	head_a = *stack_a;
	head_b = *stack_b;
	movs.stack_len_a = get_stack_len(*stack_a);
	movs.stack_len_b = get_stack_len(*stack_b);
	*stack_a = head_a;
	*stack_b = head_b;
	selected = get_selected_node(*stack_a);
	*stack_a = head_a;
	movs = get_push_a_params(stack_a, stack_b, selected, movs);
	movs = define_stack_direction(movs);
	movs = double_rotations(movs, stack_a, stack_b);
	movs = std_rotations(movs, stack_a, stack_b);
	pb(stack_a, stack_b);
}