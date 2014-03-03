/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfilename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:16:46 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/18 18:55:55 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getfilename(char *fullpath)
{
	unsigned int	start;
	unsigned int	old_start;
	unsigned int	i;

	start = 0;
	old_start = 0;
	i = 0;
	while (fullpath[i])
	{
		if (fullpath[i] == '/')
		{
			old_start = start;
			start = (i + 1);
		}
		i++;
	}
	if (start == i)
		return (ft_strsub(fullpath, old_start
							, ft_strlen(fullpath) - old_start));
	return (ft_strsub(fullpath, start, ft_strlen(fullpath) - start));
}
