/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 09:33:05 by afaucher          #+#    #+#             */
/*   Updated: 2014/01/07 09:33:09 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strintab(char *str, char **tab, int size)
{
	while (size > 0)
	{
		if (ft_strequ(str, *tab))
			return (1);
		tab++;
		size--;
	}
	return (0);
}
