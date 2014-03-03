/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:19:12 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/01 16:18:04 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char* src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	old_size;

	old_size = size;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	while (size > 1 && *dst)
	{
		dst++;
		size--;
	}
	if (old_size - size < dst_size)
		return (old_size + src_size);
	while (*src && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (dst_size + src_size);
}
