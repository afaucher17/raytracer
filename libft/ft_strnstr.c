/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:45:32 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/01 13:53:53 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*s1_save;
	const char	*s2_save;
	size_t		old_n;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && (1 + n) > 0)
	{
		s1_save = s1;
		s2_save = s2;
		old_n = n;
		while ((*s1 == *s2 || *s2 == '\0') && (1 + n--) > 0)
		{
			if (*s2 == '\0')
				return ((char *)s1_save);
			s1++;
			s2++;
		}
		s1 = s1_save;
		s2 = s2_save;
		n = old_n;
		n--;
		s1++;
	}
	return (NULL);
}
