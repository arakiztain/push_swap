/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:21:30 by arakiztain        #+#    #+#             */
/*   Updated: 2025/12/04 12:15:24 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	big_numbers(t_list **a, t_list **b)
{
	int	mv_a;
	int	mv_b;

	while (*a)
	{
		cost_to_place(*a, *b);
		mv_a = select1(*a, *b)->relp;
		mv_b = select1(*a, *b)->b;
		while (mv_a > 0 && mv_b > 0 && mv_a-- && mv_b--)
			double_rotate(&*a, &*b);
		while (mv_a < 0 && mv_b < 0 && mv_a++ && mv_b++)
			double_reverse_rotate(&*a, &*b);
		while (mv_a < 0 && mv_a++)
			rra(&*a);
		while (mv_a > 0 && mv_a--)
			ra(&*a);
		while (mv_b < 0 && mv_b++)
			rrb(&*b);
		while (mv_b > 0 && mv_b--)
			rb(&*b);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
	rotate_s_top(&*a);
}

void	cost_to_place(t_list *s, t_list *d)
{
	t_list	*temp;

	temp = d;
	while (s && d && d->next)
	{
		if (s->number > find(d, 1)->number || s->number < find(d, -1)->number)
			s->b = find(d, 1)->relp;
		else
		{
			if (s->number < ft_lstlast(d)->number && s->number > d->number)
				s->b = 0;
			while (d->next)
			{
				if (s->number < d->number && s->number > d->next->number)
					s->b = d->next->relp;
				d = d->next;
			}
			d = temp;
		}
		s = s->next;
	}
}

t_list	*select1(t_list *a, t_list *b)
{
	t_list	*selected;
	int		moves;

	moves = absolute(a->relp) + absolute(a->b);
	selected = a;
	while (a)
	{
		if (absolute(a->relp) + absolute(a->b) == moves)
		{
			if (b && ((find(b, 1)->relp > 0 && a->relp > 0)
					|| (find(b, 1)->relp < 0 && a->relp < 0)))
				selected = a;
			if (b && ((a->relp < 0 && a->b < 0)
					|| (a->relp > 0 && a->b > 0))
				&& absolute(a->relp) > absolute(a->b))
				selected = a;
		}
		if (absolute(a->relp) + absolute(a->b) < moves)
		{
			moves = absolute(a->relp) + absolute(a->b);
			selected = a;
		}
		a = a->next;
	}
	return (selected);
}
