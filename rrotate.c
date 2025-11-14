/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:52:25 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/13 17:12:11 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	if (stack_size(*stack) >= 2)
	{
		temp = *stack;
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	printf("rra\n");
}

void	rrb(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	if (stack_size(*stack) >= 2)
	{
		temp = *stack;
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("rrr\n");
}
