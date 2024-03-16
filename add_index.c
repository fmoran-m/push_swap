#include "push_swap.h"

int	get_index(int num, int *array)
{
	int	i;

	i = 0;
	while(num != array[i])
		i++;
	return (i);
}

t_stack	*add_index(t_stack *stack, int *aux_array)
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