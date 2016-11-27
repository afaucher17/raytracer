/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:23:42 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/09 18:23:44 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"libft.h"

int				ft_dlist_clear(t_dlist **list)
{
	t_dlist		*next;

	while (*list)
	{
		next = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = next;
	}
	return (1);
}
