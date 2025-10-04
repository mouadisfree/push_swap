/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:48:43 by mokatfi           #+#    #+#             */
/*   Updated: 2025/03/30 03:25:09 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checking_if_sorted(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sin;
	long	result;

	i = 0;
	sin = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sin = sin * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
		if ((result * sin) < INT_MIN)
			return (result * sin);
		else if (result > INT_MAX && (result * sin) < INT_MIN)
			return (result * sin);
	}
	return (result * sin);
}

void	ft_error(char *a)
{
	write(2, a, ft_strlen(a));
	exit(1);
}

int	ft_checking_double(t_list **a, int i)
{
	t_list	*tmp;

	if (!a || !(*a))
		return (0);
	tmp = *a;
	while (tmp)
	{
		if (tmp->content == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	checking_sign(char *s, t_list **a)
{
	int	j;

	j = 0;
	while (s[j])
	{
		if ((s[j] < '0' || s[j] > '9') && s[j] != '+' && s[j] != '-'
			&& s[j] != ' ')
		{
			free_stack(a);
			ft_error("Error\n");
		}
		if ((s[j] == '+' || s[j] == '-') && (s[j + 1] < '0' || s[j + 1] > '9'))
		{
			free_stack(a);
			ft_error("Error\n");
		}
		if ((s[j] == '+' || s[j] == '-') && (j != 0 && s[j - 1] != ' '))
		{
			free_stack(a);
			ft_error("Error\n");
		}
		j++;
	}
}
