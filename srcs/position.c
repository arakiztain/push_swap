/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:46:53 by arakiztain        #+#    #+#             */
/*   Updated: 2025/12/04 10:29:48 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	positionize(t_list **lst)
{
	if (*lst)
	{
		max_and_min (*lst);
		relative_position (*lst);
	}
}

void	max_and_min(t_list *lst)
{
	int		max;
	int		min;
	t_list	*tmp;

	max = lst->number;
	min = lst->number;
	tmp = lst;
	while (lst)
	{
		if (lst->number > max)
			max = lst->number;
		if (lst->number < min)
			min = lst->number;
		lst = lst->next;
	}
	while (tmp)
	{
		if (tmp->number == max)
			tmp->bson = 1;
		else if (tmp->number == min)
			tmp->bson = -1;
		else
			tmp->bson = 0;
		tmp = tmp->next;
	}
}

void	relative_position(t_list *lst)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst);
	if (size == 1)
		lst->relp = 0;
	while (lst->next)
	{
		if (i <= size / 2)
			lst->relp = i;
		else
			lst->relp = (size - i) * -1;
		i++;
		lst = lst->next;
		lst->relp = -1;
	}
}

void	rotate_s_top(t_list **lst)
{
	if (find(*lst, -1)->relp > 0)
		while (find(*lst, -1)->relp != 0)
			ra(&*lst);
	else if (find(*lst, -1)->relp < 0)
		while (find(*lst, -1)->relp != 0)
			rra(&*lst);
}
