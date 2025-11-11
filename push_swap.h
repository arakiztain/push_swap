/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:24:07 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/11 12:18:30 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;
int	ft_atoi(char *str);

#endif