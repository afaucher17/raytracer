/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:35:10 by afaucher          #+#    #+#             */
/*   Updated: 2013/11/27 17:05:03 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstgetprev(t_list **begin_list, t_list *elem)
{
	t_list	*cur;

	cur = *begin_list;
	if (cur == *begin_list)
		return (NULL);
	if (cur)
	{
		while (cur->next)
		{
			if (cur->next == elem)
				return (cur);
			cur = cur->next;
		}
	}
	return (NULL);
}
