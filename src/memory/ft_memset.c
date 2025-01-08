/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:38:39 by vincent           #+#    #+#             */
/*   Updated: 2025/01/08 09:46:22 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < (int)num)
	{
		*p = (unsigned char)value;
		p++;
		i++;
	}
	return (ptr);
}

