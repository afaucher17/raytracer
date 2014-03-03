/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:08:44 by afaucher          #+#    #+#             */
/*   Updated: 2014/01/22 15:11:10 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushback(t_list **alist, void *content, size_t size)
{
	t_list	*new;
	t_list	*cur;

	new = ft_lstnew(content, size);
	cur = *alist;
	if (!alist || !*alist)
		*alist = new;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}
