/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2-20.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:55:37 by mokatfi           #+#    #+#             */
/*   Updated: 2025/03/30 03:43:59 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting_2(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		ft_sa(*a, 1);
}

void	sorting_3_extra(t_list **a)
{
	if ((*a)->next->content > (*a)->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		if ((*a)->content > (*a)->next->next->content)
			ft_rra(a, 1);
	}
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content)
	{
		ft_sa(*a, 1);
	}
}

void	sorting_3(t_list **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
	{
		ft_ra(a, 1);
		if ((*a)->content > (*a)->next->content)
			ft_sa(*a, 1);
	}
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			ft_rra(a, 1);
			ft_sa(*a, 1);
		}
	}
	else
		sorting_3_extra(a);
}

void	sorting_4_20(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->content != get_minimum_value(*a))
		{
			if ((get_minimum_index(*a, get_minimum_value(*a)) <= ft_lstsize(*a)
					/ 2))
				ft_ra(a, 1);
			else
				ft_rra(a, 1);
		}
		else
			ft_pb(a, b);
	}
	sorting_3(a);
	while (*b)
		ft_pa(a, b);
}
