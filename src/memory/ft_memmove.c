/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:12:41 by ezeppa            #+#    #+#             */
/*   Updated: 2025/01/07 14:02:48 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			ptr_dest[i] = ptr_src[i];
		return (dest);
	}
	i = n;
	while (i-- > 0)
		ptr_dest[i] = ptr_src[i];
	return (dest);
}
