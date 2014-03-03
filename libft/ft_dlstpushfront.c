/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:24:03 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/09 18:29:00 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"libft.h"

void			ft_dlstpushfront(t_dlist **list,
						void *content, size_t content_size)
{
	t_dlist		*new;
	t_dlist		*cur;

	new = ft_dlstnew(content, content_size);
	cur = *list;
	if (!cur)
		*list = new;
	else
	{

		new->next = cur;
		cur->prev = new;
		*list = new;
	}
}
