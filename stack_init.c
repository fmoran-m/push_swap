#include "push_swap.h"

static void	control_digits(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while(numbers[i])
	{
		j = 0;
		if (numbers[i][j] == '-')
			j++;
		while(numbers[i][j])
		{
			if (!ft_isdigit(numbers[i][j]))
			{
				ft_putendl_fd("Error", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	check_repeat(int num, t_stack *head)
{
	while(head)
	{
		if (num == head->num)
		{
			ft_putendl_fd("Error", 2);
			exit(1); //LIBERAR!
		}
		head = head->next;
	}
}

static t_stack	*create_stack(char **numbers)
{
	int		i;
	int		num;
	t_stack	*node;
	t_stack	*head;

	i = 0;
	node = ft_stnew(ft_atoi(numbers[i]));
	if (!node)
	{
		ft_free_matrix(numbers);
		exit(1);
	}
	head = node;
	i++;
	while(numbers[i])
	{
		num = ft_atoi(numbers[i]);
		check_repeat(num, head);
		node = ft_stnew(num);
		ft_stadd_back(&head, node);
		i++;
	}
	return (head);
}

static void	check_empty_string(char *argv)
{
	int	i;

	i = 0;
	while(argv[i] == ' ')
		i++;
	if (argv[i] == 0)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

t_stack	*stack_init(char *argv)
{
	char	**numbers;
	t_stack	*stack_a;

	if (!*argv)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	check_empty_string(argv);
	numbers = ft_split(argv, ' ');
	if (!numbers)
		exit(1);
	control_digits(numbers);
	stack_a = create_stack(numbers);
	ft_free_matrix(numbers);
	return(stack_a);
}
