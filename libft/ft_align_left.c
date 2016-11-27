/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:01:41 by afaucher          #+#    #+#             */
/*   Updated: 2013/11/30 15:05:07 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_align_left(const char *str, size_t size)
{
	char	*new;
	size_t	i;

	if (size < ft_strlen(str))
		return ((char *)str);
	new = ft_strnew(size);
	i = 0;
	while (i < size)
	{
		new[i] = ' ';
		i++;
	}
	ft_strncpy(new, str, ft_strlen(str));
	return (new);
}
