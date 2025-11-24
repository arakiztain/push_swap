/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:05:02 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 11:52:33 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	absolute(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

long int	ft_atoil(const char *str)
{
	size_t		i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	ft_print_lists(t_list *a, t_list *b)
{
	printf("LISTA A:\n");
	while (a)
	{
		printf("(%2d) |%2d| (%2d)\n\n", a->relp, a->number, a->b);
		if (a->next == 0)
			break ;
		a = a->next;
	}
	printf("LISTA B:\n");
	while (b)
	{
		printf("(%2d) |%2d| (%2d)\n\n", b->relp, b->number, b->b);
		if (b->next == 0)
			break ;
		b = b->next;
	}
}

int	is_sorted(char **av)
{
	int	i;
	int	num1;
	int	num2;

	i = 0;
	while (av[i + 1] != NULL)
	{
		num1 = ft_atoi (av[i]);
		num2 = ft_atoi (av[i + 1]);
		if (num1 > num2)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
