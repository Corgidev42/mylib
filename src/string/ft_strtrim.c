/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:16:23 by ezeppa            #+#    #+#             */
/*   Updated: 2025/01/07 14:03:43 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ptr;
	int		i;

	while (*set && ft_is_set(*s1, set))
		s1++;
	i = 0;
	while (s1[i])
		i++;
	while (*set && (i - 1) > 0 && ft_is_set(s1[i - 1], set))
		i--;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (ptr);
	ft_strlcpy(ptr, s1, i + 1);
	return (ptr);
}
