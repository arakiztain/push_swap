/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:40:40 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/13 13:11:06 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	binary_len(int n)
{
	if (n <= 1)
		return (1);
	return (1 + binary_len(n / 2));
}
int	is_del(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void separator(t_node **stack_a, t_node **stack_b, int max_bits)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = stack_size(*stack_a);
	if (size < 2 || is_ordered(*stack_a))
		return ;
	while (max_bits > i)
	{
		j = 0;
		while (size > j)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;	
	}
}