/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:10:59 by afaucher          #+#    #+#             */
/*   Updated: 2013/11/21 19:41:18 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*save1;
	unsigned char	*save2;

	save1 = (unsigned char *) s1;
	save2 = (unsigned char *) s2;
	while (n > 0)
	{
		*save1 = *save2;
		save1++;
		if (*save2 == c)
			return (save1);
		save2++;
		n--;
	}
	return (NULL);
}
