/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:59:22 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 10:55:30 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	free_split(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free (input[i]);
		i++;
	}
	free (input);
}

void	free_list(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free (temp);
	}
}
