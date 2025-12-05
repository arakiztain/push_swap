/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:31:02 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 10:55:23 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	check_if_repeat(char **input)
{
	int	i;

	i = 1;
	while (*input)
	{
		while (input[i])
		{
			if (ft_atoi(*input) == ft_atoi(input[i]))
				return (0);
			i++;
		}
		i = 1;
		input++;
	}
	return (1);
}

int	ft_check_maxint(char **argv)
{
	if (ft_atoil(*argv) > 2147483647)
		return (0);
	if (ft_atoil(*argv) < -2147483648)
		return (0);
	return (1);
}

int check_elements(char **av)
{
	int i;
	int j;

	i = 0;
	while (av[i])
	{
		if (!ft_check_maxint(&av[i]))/*  */
			return (0);
		j = 0;
		if (av[i][0] == '+' || av[i][0] == '-')
		{
			if (av[i][1] == '\0')
				return (0);
			j = 1;
		}
		while (av[i][j])
		{
			if (ft_isdigit((unsigned char)av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_list_sorted(t_list *a)
{
	int	i;

	i = a->number;
	while (a)
	{
		if (i > a->number)
			return (0);
		i = a->number;
		a = a->next;
	}
	return (1);
}

int	check_order(t_list **lst, char a)
{
	t_list	*cur;
	t_list	*next;

	cur = *lst;
	next = (*lst)->next;
	while (next != NULL)
	{
		if (cur->number > next->number && a == 'a')
			return (1);
		if (cur->number < next->number && a == 'b')
			return (1);
		cur = cur->next;
		next = next->next;
	}
	return (0);
}
