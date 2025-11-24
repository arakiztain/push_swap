/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublemoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:33:11 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 10:55:27 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	double_rotate(t_list **a, t_list **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		rotate(&*a);
		rotate(&*b);
		ft_putstr_fd("rr\n");
	}
}

void	double_reverse_rotate(t_list **a, t_list **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		reverse_rotate(&*a);
		reverse_rotate(&*b);
		ft_putstr_fd("rrr\n");
	}
}

void	double_swap(t_list **a, t_list **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		swap(&*a);
		swap(&*b);
		ft_putstr_fd("ss\n");
	}
}
