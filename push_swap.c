/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:37:16 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/14 12:22:29 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Indices ordenados --> bit (x) == 1 -> B, else A. B --> A
/* bits = 0;
while ((max_index >> bits) != 0)
	bitss++; */
//Si  (n >> i) & 1 --> pb
//Si  (n >> i) & 0 --> ra
//Despues, pa hasta vaciar B y i+++

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
		new_node->next = NULL;
		*stack = new_node;
		return ;
	}
	else
	{
		new_node->value = value;
		new_node->index = -1;
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


void separator(t_node **stack_a, t_node **stack_b, int max_bits)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = stack_size(*stack_a);
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
	max = ft_index(&stack_a);
	binary_len(max);
	printf("Binary length of max index (%d): %d\n", max, binary_len(max));
	printf("Max index: %d\n", max);
	printlist(stack_a);
	separator(&stack_a, &stack_b, binary_len(max));
	printf("After sorting:\n");
	printlist(stack_a);
	printlist(stack_b);
	return (0);
}

