/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:13:35 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/01 14:47:07 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strtrim(char const *s)
{
	size_t			len;
	size_t			spaces;
	const char		*save;

	len = 0;
	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	save = s;
	while (*save)
	{
		spaces = 0;
		while (*save == ' ' || *save == '\t' || *save == '\n' || *save == '\0')
		{
			if (!*save)
				return (ft_strsub(s, 0, len));
			spaces++;
			save++;
		}
		len += spaces;
		len++;
		save++;
	}
	return (ft_strsub(s, 0, len));
}
