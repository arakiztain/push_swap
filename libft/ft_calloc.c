/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garakizt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:04:53 by garakizt          #+#    #+#             */
/*   Updated: 2025/10/14 14:50:55 by garakizt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"
#include <stdint.h>

void	*ft_calloc(size_t mem, size_t size)
{
	void	*ptr;

	if (mem != 0 && size > SIZE_MAX / mem)
		return (NULL);
	ptr = malloc(mem * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, mem * size);
	return (ptr);
}
