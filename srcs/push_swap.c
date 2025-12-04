/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:50:17 by garakizt          #+#    #+#             */
/*   Updated: 2025/12/04 11:59:25 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	start_push_swap(char **input)
{
	t_list	*a;
	t_list	*b;
	int		size;

	b = NULL;
	create_linked_list(&a, input);
	size = ft_lstsize(a);
	if (size == 2)
		sa(&a);
	else if (size == 3)
		three_numbers(&a);
	else if (size <= 5 && size > 1)
		five_numbers(&a, &b);
	else
		big_numbers(&a, &b);
	free_list(a);
}

void	create_linked_list(t_list **stack, char **input)
{
	t_list	*temp;
	int		i;

	i = 1;
	*stack = ft_lstnew(ft_atoi(*input));
	while (input[i])
	{
		ft_lstadd_back(&*stack, ft_lstnew(ft_atoi(input[i])));
		i++;
	}
	index_stack(&*stack);
	temp = *stack;
	while (temp)
	{
		temp->b = 0;
		temp = temp->next;
	}
	max_and_min(*stack);
	relative_position(*stack);
}

t_list	*get_min(t_list	**stack)
{
	t_list	*head;
	t_list	*smllst_n;
	int		min;

	if (!stack || !*stack)
		return (NULL);
	head = *stack;
	smllst_n = NULL;
	min = 0;
	while (head)
	{
		if (head->index == -1 && (!min || head->number < smllst_n->number))
		{
			smllst_n = head;
			min = 1;
		}
		head = head->next;
	}
	return (smllst_n);
}

void	index_stack(t_list	**stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_min(&*stack);
	while (head != NULL)
	{
		head->index = index++;
		head = get_min(stack);
	}
}
