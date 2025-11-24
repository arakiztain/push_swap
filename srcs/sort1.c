/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:07:07 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 11:58:25 by arakiztain       ###   ########.fr       */
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

void	sort_b_3(t_list **a, t_list **b)
{
	int	size;
	int	inditex;

	inditex = 0;
	size = ft_lstsize(*a);
	while (size > 3)
	{
		if ((*a)->index == inditex)
		{
			pb(a, b);
			size--;
			inditex++;
		}
		else if ((*a)->index != inditex)
		{
			ra(a);
		}
	}
}

void	five_numbers(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 3 && !check_list_sorted(*a))
	{
		sort_b_3(a, b);
		three_numbers(a);
	}
	while ((*b)->index != 0)
	{
		pa(a, b);
	}
	if ((*b)->index == 0)
		pa(a, b);
}
