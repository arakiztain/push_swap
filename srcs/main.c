/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:37:16 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 11:50:34 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	char	**input;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		if (!check_if_repeat(input) || !check_elements(input))
			return (free_split(input), ft_putstr_fd("Error\n"), 0);
		if (!is_sorted(input))
		{
			free_split(input);
			return (0);
		}
		return (start_push_swap(input), free_split(input), 0);
	}
	else
	{
		if (!check_if_repeat(av + 1) || !check_elements(av + 1))
			return (ft_putstr_fd("Error\n"), 0);
		if (!is_sorted(av + 1))
			return (0);
		start_push_swap(av + 1);
	}
	return (0);
}
