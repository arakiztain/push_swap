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

static int	find_best_in_range(t_list *a, int start, int end, int size, int *relp)
{
    int	pos;
    int	best_moves;
    int	best_rel;
    int	found;

    pos = 0;
    best_moves = size + 1;
    best_rel = 0;
    found = 0;
    while (a)
    {
        if (a->index >= start && a->index < end)
        {
            int	rel = (pos <= size / 2) ? pos : pos - size;
            if (absolute(rel) < best_moves)
            {
                best_moves = absolute(rel);
                best_rel = rel;
                found = 1;
            }
        }
        pos++;
        a = a->next;
    }
    return (*relp = best_rel, found);
}

void	big_numbers(t_list **a, t_list **b)
{
    int	size;
    int	chunk;
    int	start;
    int	end;
    int	rel;
    int	size_a;

    size = ft_lstsize(*a);
    if (size <= 1)
        return ;
    chunk = (size <= 100) ? 17 : (size <= 500 ? 60 : 45);
    start = 0;
    while (start < size)
    {
        end = start + chunk;
        if (end > size)
            end = size;
        size_a = ft_lstsize(*a);
        while (find_best_in_range(*a, start, end, size_a, &rel))
        {
            if (rel > 0)
                while (rel--)
                    ra(a);
            else
                while (rel++ < 0)
                    rra(a);
            pb(a, b);
            /* rotar B sólo si el elemento es de la mitad inferior del chunk */
            if (*b && (*b)->index <= start + (chunk / 2))
                rb(b);
            size_a = ft_lstsize(*a);
        }
        start = end;
    }
    while (*b)
    {
        int	pos;
        int	max_idx;
        int	size_b;
        t_list *tmp;

        tmp = *b;
        max_idx = tmp->index;
        while (tmp)
        {
            if (tmp->index > max_idx)
                max_idx = tmp->index;
            tmp = tmp->next;
        }
        tmp = *b;
        pos = 0;
        size_b = ft_lstsize(*b);
        while (tmp && tmp->index != max_idx)
            tmp = tmp->next, pos++;
        rel = (pos <= size_b / 2) ? pos : pos - size_b;
        if (rel > 0)
            while (rel--)
                rb(b);
        else
            while (rel++ < 0)
                rrb(b);
        pa(a, b);
    }
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
