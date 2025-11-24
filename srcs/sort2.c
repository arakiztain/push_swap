/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:21:30 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 12:52:18 by arakiztain       ###   ########.fr       */
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

void	cost_to_place(t_list *src, t_list *dst)
{
	t_list	*temp;
	int		n;

	n = src->number;
	temp = dst;
	while (src && dst && dst->next)
	{
		if (n > find(dst, 1)->number || n < find(dst, -1)->number)
			src->b = find(dst, 1)->relp;
		else
		{
			if (n < ft_lstlast(dst)->number && n > dst->number)
				src->b = 0;
			while (dst->next)
			{
				if (n < dst->number && n > dst->next->number)
					src->b = dst->next->relp;
				dst = dst->next;
			}
			dst = temp;
		}
		src = src->next;
	}
}

static int	get_moves(t_list *x)
{
	return (absolute(x->relp) + absolute(x->b));
}

static int	valid_match(t_list *a, t_list *b)
{
	int	br;

	if (!b)
		return (0);
	br = find(b, 1)->relp;
	if ((br > 0 && a->relp > 0) || (br < 0 && a->relp < 0))
		return (1);
	if (((a->relp < 0 && a->b < 0) || (a->relp > 0 && a->b > 0))
		&& absolute(a->relp) > absolute(a->b))
		return (1);
	return (0);
}

t_list	*select1(t_list *a, t_list *b)
{
	t_list	*selected;
	int		moves;
	int		current;

	selected = a;
	moves = get_moves(a);
	while (a)
	{
		current = get_moves(a);
		if (current == moves && valid_match(a, b))
			selected = a;
		else if (current < moves)
		{
			moves = current;
			selected = a;
		}
		a = a->next;
	}
	return (selected);
}
