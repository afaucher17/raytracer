/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:31:30 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/01 13:51:56 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*s1_save;
	const char	*s2_save;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		s1_save = s1;
		s2_save = s2;
		while (*s1 == *s2 || *s2 == '\0')
		{
			if (*s2 == '\0')
				return ((char *)s1_save);
			s1++;
			s2++;
		}
		s1 = s1_save;
		s2 = s2_save;
		s1++;
	}
	return (NULL);
}
