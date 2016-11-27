/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:27:57 by afaucher          #+#    #+#             */
/*   Updated: 2013/11/30 17:53:39 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_align_right(const char *str, size_t size)
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
	ft_strcpy(new + (size - ft_strlen(str)), str);
	return (new);
}
