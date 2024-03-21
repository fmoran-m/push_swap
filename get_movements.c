#include "push_swap.h"

t_movs	movs_init(int movs_a, int movs_b, int stack_len_a, int stack_len_b)
{
	t_movs	movs;

	movs.movs_a = movs_a;
	movs.movs_b = movs_b;
	movs.stack_len_a = stack_len_a;
	movs.stack_len_b = stack_len_b;
	movs.med_a = (float)stack_len_a / 2;
	movs.med_b = (float)stack_len_b / 2;
	movs.total_movs = movs.movs_a + movs.movs_b;
	return (movs);
}

int	get_movs(int movs_a, int movs_b, int stack_len_a, int stack_len_b)
{
	t_movs	movs;

	movs = movs_init(movs_a, movs_b, stack_len_a, stack_len_b);
	if ((movs.movs_a <= movs.med_a) && (movs.movs_b <= movs.med_b))
		return(both_below_median(movs));
	else if ((movs.movs_a > movs.med_a) && (movs.movs_b > movs.med_b))
		return(both_above_median(movs));
	else if(movs.movs_a > movs.med_a)
		return(a_above_median(movs));
	else if(movs.movs_b > movs.med_b)
		return(b_above_median(movs));
	else
		return(movs.total_movs);
}

void	get_cheaper_num(t_stack **stack_a, t_stack **stack_b)
{
	int		stack_len_a;
	int		stack_len_b;
	int		movs_a;
	int		movs_b;
	t_stack	*head_b;

	head_b = *stack_b;
	stack_len_a = get_stack_len(*stack_a);
	stack_len_b = get_stack_len(*stack_b);
	movs_a = 0;
	while(*stack_a)
	{
		movs_b = 0;
		*stack_b = head_b;
		while ((*stack_a)->obj_node != *stack_b)
		{
			movs_b++;
			*stack_b = (*stack_b)->next;
		}
		(*stack_a)->movs = get_movs(movs_a, movs_b, stack_len_a, stack_len_b);
		movs_a++;
		*stack_a = (*stack_a)->next;
	}
}