/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:04:10 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/01 12:55:16 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*save1;
	unsigned char	*save2;

	save1 = (unsigned char *)s1;
	save2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*save1 != *save2)
			return (*save1 - *save2);
		save1++;
		save2++;
		n--;
	}
	return (0);
}
