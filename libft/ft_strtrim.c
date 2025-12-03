/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garakizt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:15:03 by garakizt          #+#    #+#             */
/*   Updated: 2025/10/15 11:20:41 by garakizt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_strchar(char const *str, char const c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(char const *s1, char const *set)
{
	int		start;

	start = 0;
	while (s1[start] && ft_strchar(set, s1[start]))
		start++;
	return (start);
}

static int	ft_end(char const *s1, char const *set)
{
	int	end;

	end = 0;
	while (s1[end])
		end++;
	end--;
	while (end >= 0 && ft_strchar(set, s1[end]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	int		i;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	len = end - start + 1;
	if (len < 0)
		len = 0;
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (start <= end)
		r[i++] = s1[start++];
	r[i] = '\0';
	return (r);
}

/*
int	main(void)
{
	printf("%s",ft_strtrim("123Hola321", "123"));
	return (0);
}*/
