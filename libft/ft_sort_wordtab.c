/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:37:41 by afaucher          #+#    #+#             */
/*   Updated: 2013/11/27 15:43:31 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_wordtab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i][0])
	{
		j = i + 1;
		while (tab[j][0] != '\0')
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_swap(&(tab[i]), &(tab[j]));
			j++;
		}
		i++;
	}
}
