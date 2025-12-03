/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:09:16 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/24 11:09:18 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t mem, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif