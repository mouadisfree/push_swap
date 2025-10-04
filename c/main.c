/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:41:07 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/01 22:33:12 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_calling_nodes(t_list **a, char **s, char *c)
{
	int	i;

	if (ft_atoi(c) > 2147483647 || ft_atoi(c) < -2147483648)
	{
		free(c);
		free(s);
		free_stack(a);
		ft_error("Error\n");
	}
	if (ft_checking_double(a, ft_atoi(c)) == 1)
	{
		i = 0;
		while (s[i])
			free(s[i++]);
		free(s);
		free_stack(a);
		ft_error("Error\n");
	}
	ft_lstadd_back(a, ft_lstnew(ft_atoi(c)));
}

void	putting_to_stack(char **av, int i, t_list **a, char **s)
{
	int	k;

	while (av[i])
	{
		checking_sign(av[i], a);
		s = ft_split(av[i], 32);
		if (!s[0])
		{
			free(s);
			free_stack(a);
			ft_error("Error\n");
		}
		k = 0;
		while (s[k])
		{
			ft_calling_nodes(a, s, s[k]);
			free(s[k]);
			k++;
		}
		free(s);
		i++;
	}
}

void	ft_choosing_sorting_function(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sorting_2(a);
	if (ft_lstsize(*a) == 3)
		sorting_3(a);
	if (ft_lstsize(*a) >= 4 && ft_lstsize(*a) <= 20)
		sorting_4_20(a, b);
	if (ft_lstsize(*a) > 20 && ft_lstsize(*a) <= 100)
		sorting_100(a, b);
	if (ft_lstsize(*a) > 100)
		sorting_500(a, b);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*b;
	char	**s;

	a = NULL;
	b = NULL;
	s = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	putting_to_stack(av, i, &a, s);
	if (checking_if_sorted(a))
	{
		free_stack(&a);
		exit(0);
	}
	ft_choosing_sorting_function(&a, &b);
	free_stack(&a);
	return (0);
}
