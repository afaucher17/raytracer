/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 19:01:39 by afaucher          #+#    #+#             */
/*   Updated: 2014/01/06 19:01:41 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	c = (char)c;
	if (*s == '\0' && c != '\0')
		return (NULL);
	while (*s)
		s++;
	if (*s == c)
		return ((char *)s);
	s--;
	while (*s)
	{
		if (*s == c)
		return ((char *)s);
		s--;
	}
	return (NULL);
}
