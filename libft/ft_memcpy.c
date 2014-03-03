/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:53:55 by afaucher          #+#    #+#             */
/*   Updated: 2013/11/27 19:20:23 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*save1;
	unsigned char	*save2;

	save1 = (unsigned char *) s1;
	save2 = (unsigned char *) s2;
	if (!s2)
		return (s1);
	while (n > 0)
	{
		*save1 = *save2;
		save1++;
		save2++;
		n--;
	}
	return (s1);
}
