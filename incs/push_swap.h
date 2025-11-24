/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:24:07 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 10:47:31 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include <limits.h>

typedef struct s_list
{
	int				number;
	int				index;
	int				relp;
	int				bson;
	int				b;
	struct s_list	*next;
}					t_list;

				//checks:
int			check_if_repeat(char **av);
int			check_args(char **input);
int			check_elements(char	**av);
int			is_sorted(char **av);
int			check_list_sorted(t_list *a);
int			ft_check_maxint(char **argv);
long int	ft_atoil(const char *str);

int			absolute(int num);
long int	ft_atoil(const char *str);
int			is_sorted(char **av);

				//free:
void		free_split(char **input);
void		free_list(t_list *lst);

void		create_linked_list(t_list **head, char **input);
t_list		*ft_lstnew(int number);
void		ft_lstadd_back(t_list **stack, t_list *new);
t_list		*ft_lstlast(t_list *head);
int			ft_lstsize(t_list *lst);
void		start_push_swap(char **input);
void		printLinkedList(t_list *head);
void		ft_print_lists(t_list *a, t_list *b);
//void		sort(t_list **a, t_list **b);
void		five_numbers(t_list **a, t_list **b);
int			check_order(t_list **lst, char a);
void		medium_sort(t_list **a, t_list **b);
int			cost_in_a(t_list *a, int nbr);
//int			check_max_min(t_list *lst, int number, char c);
void		three_numbers(t_list **a);
int			ft_rotate_ab(t_list **a, t_list **b);
void		max_and_min(t_list *lst);
void		insert_sorted(t_list **a, t_list **b);
int			absolute(int num);
void		big_numbers(t_list **a, t_list **b);

t_list		*get_min(t_list	**stack);

						//position:
void		max_and_min(t_list *lst);
void		relative_position(t_list *lst);
t_list		*find(t_list *node, int bson);
void		positionize(t_list **lst);

void		insert(t_list **b, t_list **a, t_list *node);
void		cost_to_place(t_list *src, t_list *dst);
t_list		*select1(t_list *lst, t_list *b);

						//movements:
void		push(t_list	**src, t_list	**dst);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);

void		rotate(t_list **lst);
void		ra(t_list **a);
void		rb(t_list **b);
void		double_rotate(t_list **a, t_list **b);

void		reverse_rotate(t_list **lst);
void		rra(t_list **a);
void		rrb(t_list **b);
void		double_reverse_rotate(t_list **a, t_list **b);

void		swap(t_list **lst);
void		sa(t_list **a);
void		sb(t_list **b);
void		double_swap(t_list **a, t_list **b);

void		rotate_s_top(t_list **lst);
void		finish(t_list **lst);
						//index:
void		index_stack(t_list	**stack);

#endif