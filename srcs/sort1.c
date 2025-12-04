/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:07:07 by arakiztain        #+#    #+#             */
/*   Updated: 2025/12/04 11:53:48 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	three_numbers(t_list **a)
{
	t_list	*first;
	t_list	*second;
	t_list	*th;

	while (check_order(a, 'a') == 1)
	{
		first = (*a);
		second = (*a)->next;
		th = (*a)->next->next;
		if (first->number > second->number && first->number < th->number)
			sa(a);
		else if (first->number > second->number && first->number > th->number)
			ra(a);
		else if (first->number < second->number && first->number > th->number)
			rra(a);
		else if (first->number < second->number && first->number < th->number)
			sa(a);
	}
}

static int	get_pos(t_list *a, int inditex)
{
	int	pos;

	pos = 0;
	while (a && a->index != inditex)
	{
		a = a->next;
		pos++;
	}
	if (!a)
		return (-1);
	return (pos);
}

static void	rotate_and_push(t_list **a, t_list **b, int rel)
{
	if (rel > 0)
		while (rel--)
			ra(a);
	else
		while (rel++ < 0)
			rra(a);
	pb(a, b);
}

void	sort_b_3(t_list **a, t_list **b)
{
	int	size;
	int	inditex;
	int	pos;
	int	rel;

	size = ft_lstsize(*a);
	inditex = 0;
	while (size > 3)
	{
		pos = get_pos(*a, inditex);
		if (pos >= 0)
		{
			if (pos <= size / 2)
				rel = pos;
			else
				rel = pos - size;
			rotate_and_push(a, b, rel);
			size--;
		}
		inditex++;
	}
}

void	five_numbers(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 3 && !check_list_sorted(*a))
	{
		sort_b_3(a, b);
		three_numbers(a);
	}
	while (*b)
		pa(a, b);
}
