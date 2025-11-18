/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:07:07 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/18 13:21:56 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_a(t_node **stack_a)
{
	t_node	*temp;
	int		i;
	int		size;

	size = stack_size(*stack_a);
	temp = *stack_a;
	i = 0;
	while (temp)
	{
		//ra
		if (i <= size / 2)
			temp->cost_a = i;
		//rra
		else
			temp->cost_a = size - i;
		temp = temp->next;
		i++;
	}
}

void calculate_cost_b(t_node **stack_a, t_node **stack_b)
{
    t_node	*temp_a;
    t_node	*temp_b;
    int		size_b;
    int		i;

    temp_a = *stack_a;
    while (temp_a)
    {
        temp_b = *stack_b;
        i = 0;
        while (temp_b)
        {
            if (temp_b->value == temp_a->target)
            {
                if (i <= stack_size(*stack_b) / 2)
                    temp_a->cost_b = i;
                else
                    temp_a->cost_b = stack_size(*stack_b) - i;
                break;
            }
            i++;
        	temp_b = temp_b->next;
        }
        temp_a = temp_a->next;
    }
}

void	calculate_costs(t_node **stack_a, t_node **stack_b)
{
	cost_a(stack_a);
	calculate_cost_b(stack_a, stack_b);
}

int	total_cost(t_node *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs(cost_a) > abs(cost_b))
			return (abs(cost_a));
		else
			return (abs(cost_b));
	}
	else
		return (abs(cost_a) + abs(cost_b));
}

t_node *find_cheapest_node(t_node **stack_a)
{
    t_node	*temp;
    t_node	*cheapest;
    int		min_total;
	int		t;

	temp = *stack_a;
	cheapest = temp;
	min_total = total_cost(temp);
    while (temp)
    {
        t = total_cost(temp);
        if (t < min_total)
        {
            min_total = t;
            cheapest = temp;
        }
        temp = temp->next;
    }
    return (cheapest);
}

