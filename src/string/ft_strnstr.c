/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:17:25 by ezeppa            #+#    #+#             */
/*   Updated: 2025/01/07 14:03:38 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr_big;
	size_t	big_len;
	size_t	little_len;

	ptr_big = (char *)big;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (len > 0 && big_len >= little_len && len >= little_len)
	{
		if (ft_memcmp(ptr_big, little, little_len) == 0)
			return (ptr_big);
		ptr_big++;
		len--;
	}
	return (NULL);
}
