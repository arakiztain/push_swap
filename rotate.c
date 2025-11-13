/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:18:45 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/13 14:47:22 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack)
{
	t_node	*first;
	t_node	*temp;

	if (stack_size(*stack) >= 2)
	{
		first = *stack;
		*stack = (*stack)->next;
		first->next = NULL;
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = first;
	}
	printf("ra\n");
}

void	rb(t_node **stack)
{
	t_node	*first;
	t_node	*temp;

	if (stack_size(*stack) >= 2)
	{
		first = *stack;
		*stack = (*stack)->next;
		first->next = NULL;
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = first;
	}
	printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	printf("rr\n");
}
