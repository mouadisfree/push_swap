/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:26:30 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/01 18:34:10 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	putting_max_index_at_top_ff(t_list **b, int index)
{
	if (get_max_index_position_in_b(*b, index) >= ft_lstsize(*b) / 2)
		while ((*b)->index != index)
			ft_rrb(b, 1);
	else
		while ((*b)->index != index)
			ft_rb(b, 1);
}

void	pushing_back_to_a_ff(t_list **a, t_list **b, t_list2 val)
{
	val.max_index = ft_lstsize(*b) - 1;
	while (*b)
	{
		if (val.max_index == (*b)->index)
		{
			ft_pa(a, b);
			val.max_index--;
		}
		else if (val.max_index == get_last_index_in_a(*a))
		{
			ft_rra(a, 1);
			val.max_index--;
		}
		else if ((*b)->index > get_last_index_in_a(*a))
		{
			ft_pa(a, b);
			ft_ra(a, 1);
		}
		else
			putting_max_index_at_top_ff(b, val.max_index);
	}
}

void	checking_stack_a_ff(t_list **a, t_list **b, t_list2 val)
{
	pushing_back_to_a_ff(a, b, val);
	while (!checking_if_sorted(*a))
		ft_rra(a, 1);
}

void	expanding_chunk_ff(t_list2 *val)
{
	if (val->chunk == 0 && val->offset <= val->middle)
	{
		val->chunk = 80;
		val->offset += val->chunk / 2;
	}
}

void	sorting_500(t_list **a, t_list **b)
{
	t_list2	val;

	ranking_values(*a);
	val.chunk = 80;
	val.middle = ft_lstsize(*a) / 2;
	val.offset = val.chunk / 2;
	while (*a)
	{
		val.start = val.middle - val.offset;
		val.end = val.middle + val.offset;
		if (val.chunk != 0)
		{
			if ((*a)->index >= val.start && (*a)->index < val.end)
			{
				ft_pb(a, b);
				if ((*b)->index < val.middle)
					ft_rb(b, 1);
				val.chunk--;
			}
			else
				ft_ra(a, 1);
		}
		expanding_chunk_ff(&val);
	}
	checking_stack_a_ff(a, b, val);
}
