/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:39:11 by vbonnard          #+#    #+#             */
/*   Updated: 2025/05/21 11:39:12 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *s, size_t size)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (ptr);
	ft_strlcpy(ptr, s, size);
	return (ptr);
}
