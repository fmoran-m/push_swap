#include "push_swap.h"

static void	control_digits(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while(numbers[i])
	{
		j = 0;
		while(numbers[i][j])
		{
			if (!ft_isdigit(numbers[i][j]))
			{
				ft_printf("Error!\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static t_stack	*create_stack(char **numbers)
{
	int		i;
	t_stack	*node;
	
	i = 0;
	stack = NULL;
	while(numbers[i])
	{
		node = ft_stnew(ft_atoi(numbers[i]));
		if (!node)
		{
			ft_free_matrix(numbers);
			exit(1);
		}
		else
			ft_stadd_back(stack, node);
		i++;
	}
	return (*stack);
}

t_stack	*stack_init(char *argv)
{
	char	**numbers;
	t_stack	*stack_a;

	numbers = ft_split(argv, ' ');
	if (!ft_split)
		exit(1);
	control_digits(numbers);
	stack_a = create_stack(numbers);
	ft_free_matrix(numbers);
	return(stack_a);
}
