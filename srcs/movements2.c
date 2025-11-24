/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:52:25 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 10:55:47 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ra(t_list **a)
{
	rotate(a);
	ft_putstr_fd("ra\n");
}

void	rb(t_list **b)
{
	rotate(b);
	ft_putstr_fd("rb\n");
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_putstr_fd("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr_fd("pb\n");
}
