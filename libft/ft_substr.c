/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garakizt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:17:38 by garakizt          #+#    #+#             */
/*   Updated: 2025/10/14 14:53:10 by garakizt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static size_t	ft_actual_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (0);
	if (s_len - start < len)
		return (s_len - start);
	return (len);
}

static char	*ft_alloc_substr(size_t actual_len)
{
	char	*r;

	r = (char *)malloc(actual_len + 1);
	if (!r)
		return (NULL);
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;
	size_t	actual_len;

	if (!s)
		return (NULL);
	actual_len = ft_actual_len(s, start, len);
	r = ft_alloc_substr(actual_len);
	if (!r)
		return (NULL);
	i = 0;
	while (i < actual_len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
/*
int	main(void)
{
	printf("%s", ft_substr("hola mundo", 6, 3));
}*/
