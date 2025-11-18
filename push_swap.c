/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:37:16 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/18 12:33:56 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	if (*stack == NULL)
	{
		new_node->value = value;
		new_node->index = -1;
		new_node->target = -1;
		new_node->next = NULL;
		*stack = new_node;
		return ;
	}
	else
	{
		new_node->value = value;
		new_node->index = -1;
		new_node->target = -1;
		new_node->next = NULL;
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	ft_split(char *str, t_node **stack_a)
{
	int		i;
	int		start;

	i = 0;
	if (is_del(str))
	{
		while (str[i])
		{
			if (str[i] != ' ')
			{
				start = i;
				while (str[i] != ' ' && str[i] != '\0')
					i++;
				create_node(stack_a, ft_atoi(&str[start]));
			}
			else
				i++;
		}
	}
	else
		create_node(stack_a, ft_atoi(&str[i]));
}

int	has_unindexed(t_node *stack)
{
	while (stack)
	{
		if (stack->index == -1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_index(t_node **stack_a)
{
	t_node	*temp;
	t_node	*min_node;
	int		i;

	i = 0;
	while (has_unindexed(*stack_a))
	{
		temp = *stack_a;
		min_node = NULL;
		while (temp != NULL)
		{
			if (temp->index == -1)
			{
				if (min_node == NULL || temp->value < min_node->value)
					min_node = temp;
			}
			temp = temp->next;
		}
		if (min_node)
			min_node->index = i++;
	}
	return (i - 1);
}

void	printlist(t_node *stack)
{
	while (stack)
	{
		printf("Value: %d, Index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
}

void	operator(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		size;
	t_node	*temp;

	size = stack_size(stack_a);
	if (size < 2 || is_ordered(stack_a))
		return ;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	temp = *stack_a;
	while (temp)
	{
		temp->target = get_target(temp->value, stack_b);
		temp = temp->next;
	}
	calculate_costs(stack_a, stack_b);
	
}

int	get_target(int value, t_node **stack_b)
{
	int 	closest;
	int		assigned;
	int		max;
	t_node	*temp;

	temp = *stack_b;
	closest = 0;
	assigned = 0;
	max = 0;
	while(temp)
	{
		if (value > temp->value && (temp->value > closest || closest == 0))
		{
			assigned = 1;
			closest = temp->value;
		}
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	if (assigned == 0)
		closest = max;
	return (closest);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	int		max;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc != 1)
	{
		while (argv[i])
		{
			ft_split(argv[i], &stack_a);
			i++;
		}
	}
	if (checker(&stack_a))
		return (1);
	max = ft_index(&stack_a);
	binary_len(max);
	/* printf("Binary length of max index (%d): %d\n", max, binary_len(max));
	printf("Max index: %d\n", max); */
	printlist(stack_a);
	operator(&stack_a, &stack_b);
	printf("After sorting:\n");
	//printlist(stack_a);
	printlist(stack_b);
	return (0);
}

