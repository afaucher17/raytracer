/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:50:40 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/01 14:13:41 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*save;

	save = (unsigned char *)s;
	c = (unsigned char)c;
	while (n > 0)
	{
		if (*save == c)
			return (save);
		save++;
		n--;
	}
	return (NULL);
}
