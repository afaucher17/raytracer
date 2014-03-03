/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:19:36 by afaucher          #+#    #+#             */
/*   Updated: 2013/11/22 14:34:22 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*save1;
	char	*save2;

	save1 = (char *) s1;
	save2 = (char *) s2;
	if ((save1 < save2) || (save1 + n) < save2)
		return (ft_memcpy(s1, s2, n));
	while (n > 0)
	{
		*(save1 + n - 1) = *(save2 + n - 1);
		n--;
	}
	return (s1);
}
