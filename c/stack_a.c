/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:04:40 by mokatfi           #+#    #+#             */
/*   Updated: 2025/03/30 03:44:10 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_rra(t_list **a, int k)
{
	t_list	*last;
	t_list	*ret;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	ret = *a;
	while (last->next)
	{
		ret = last;
		last = last->next;
	}
	last->next = *a;
	*a = last;
	ret->next = NULL;
	if (k == 1)
		ft_putstr("rra\n");
}

void	ft_ra(t_list **a, int k)
{
	t_list	*first;
	t_list	*last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	first->next = NULL;
	while (last->next)
		last = last->next;
	last->next = first;
	if (k == 1)
		ft_putstr("ra\n");
}

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*first_a;
	t_list	*first_b;

	if (b == NULL || *b == NULL)
		return ;
	first_a = *a;
	first_b = *b;
	*b = (*b)->next;
	if (*a)
	{
		*a = first_b;
		first_b->next = first_a;
	}
	else
	{
		*a = first_b;
		first_b->next = NULL;
	}
	ft_putstr("pa\n");
}

void	ft_sa(t_list *a, int k)
{
	int	tmp;

	if (!a)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
	if (k == 1)
		ft_putstr("sa\n");
}
