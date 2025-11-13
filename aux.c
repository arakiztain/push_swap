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
