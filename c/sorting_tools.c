/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:58:41 by mokatfi           #+#    #+#             */
/*   Updated: 2025/03/30 00:48:47 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_index_position_in_b(t_list *b, int max)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!b)
		return (0);
	tmp = b;
	while (tmp)
	{
		i++;
		if (tmp->index == max)
			return (i);
		tmp = tmp->next;
	}
	return (0);
}

int	get_last_index_in_a(t_list *a)
{
	int		last;
	t_list	*tmp;

	last = 0;
	tmp = a;
	if (tmp != NULL)
	{
		while (tmp)
		{
			last = (tmp)->index;
			tmp = (tmp)->next;
		}
	}
	return (last);
}

t_list	*minimum_unindexed_value(t_list *a)
{
	t_list	*tmp;
	t_list	*min;

	tmp = a;
	while (tmp->index != -1)
		tmp = tmp->next;
	min = tmp;
	while (tmp)
	{
		if (tmp->index == -1 && min->content > tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	get_minimum_value(t_list *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	get_minimum_index(t_list *a, int min)
{
	int		i;
	t_list	*temp;

	temp = a;
	i = 0;
	while (temp)
	{
		if (min == temp->content)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}
