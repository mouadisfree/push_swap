/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:13:03 by mokatfi           #+#    #+#             */
/*   Updated: 2025/03/30 03:44:15 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrb(t_list **b, int k)
{
	t_list	*last;
	t_list	*ret;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	ret = *b;
	while (last->next)
	{
		ret = last;
		last = last->next;
	}
	last->next = *b;
	*b = last;
	ret->next = NULL;
	if (k == 1)
		ft_putstr("rrb\n");
}

void	ft_rb(t_list **b, int k)
{
	t_list	*first;
	t_list	*last;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	*b = (*b)->next;
	last = *b;
	first->next = NULL;
	while (last->next)
		last = last->next;
	last->next = first;
	if (k == 1)
		ft_putstr("rb\n");
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*first_a;
	t_list	*first_b;

	if (a == NULL || *a == NULL)
		return ;
	first_a = *a;
	first_b = *b;
	*a = (*a)->next;
	if (*b)
	{
		*b = first_a;
		first_a->next = first_b;
	}
	else
	{
		*b = first_a;
		first_a->next = NULL;
	}
	ft_putstr("pb\n");
}

void	ft_sb(t_list *b, int k)
{
	int	tmp;

	if (!b)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	if (k == 1)
		ft_putstr("sb\n");
}
