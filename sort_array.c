#include "push_swap.h"

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

int	*bubblesort(t_stack *stack_a, int stack_len)
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