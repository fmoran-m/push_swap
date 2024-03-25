#include "../push_swap.h"

static t_movs	rrr_updt_movs(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	rrr(stack_a, stack_b);
	movs.movs_a--;
	movs.movs_b--;
	return (movs);
}

static t_movs	rr_updt_movs(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	rr(stack_a, stack_b);
	movs.movs_a--;
	movs.movs_b--;
	return (movs);
}

static t_movs	rra_rb_updt_movs(t_movs movs, t_stack **stack_a,
		t_stack **stack_b)
{
	rra(stack_a, PRINT);
	rb(stack_b, PRINT);
	movs.movs_a--;
	movs.movs_b--;
	return (movs);
}

static t_movs	ra_rrb_updt_movs(t_movs movs, t_stack **stack_a,
		t_stack **stack_b)
{
	ra(stack_a, PRINT);
	rrb(stack_b, PRINT);
	movs.movs_a--;
	movs.movs_b--;
	return (movs);
}

t_movs	double_rotations(t_movs movs, t_stack **stack_a, t_stack **stack_b)
{
	while (movs.movs_a > 0 && movs.movs_b > 0)
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
	return (movs);
}
