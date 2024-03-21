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

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*selected;
	t_stack		*head_a;
	t_stack		*head_b;
	t_movs		movs;

	head_a = *stack_a;
	head_b = *stack_b;
	selected = get_selected_node(*stack_a);
	*stack_a = head_a;
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
	movs.stack_len_a = get_stack_len(*stack_a);
	*stack_a = head_a;
	movs.stack_len_b = get_stack_len(*stack_b);
	*stack_b = head_b;
	movs.med_a = (float)movs.stack_len_a / 2;
	movs.med_b = (float)movs.stack_len_b / 2;
	movs.rev_flag_a = 0;
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
	while(movs.movs_a > 0 && movs.movs_b > 0)
	{
		if (movs.rev_flag_a && movs.rev_flag_b)
		{
			rrr(stack_a, stack_b);
			movs.movs_a--;
			movs.movs_b--;
		}
		else if (!movs.rev_flag_a && !movs.rev_flag_b)
		{
			rr(stack_a, stack_b);
			movs.movs_a--;
			movs.movs_b--;
		}
		else if (movs.rev_flag_a && !movs.rev_flag_b)
		{
			rra(stack_a, PRINT);
			rb(stack_b, PRINT);
			movs.movs_a--;
			movs.movs_b--;
		}
		else
		{
			ra(stack_a, PRINT);
			rrb(stack_b, PRINT);
			movs.movs_a--;
			movs.movs_b--;
		}
	}
	while(movs.movs_a > 0)
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
	}
	while(movs.movs_b > 0)
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
	}
	pb(stack_a, stack_b);
}