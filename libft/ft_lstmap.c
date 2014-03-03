/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:30:16 by afaucher          #+#    #+#             */
/*   Updated: 2013/11/30 18:01:23 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cur;
	t_list	*new;
	t_list	*cpy;

	cur = lst;
	new = NULL;
	while (cur)
	{
		cpy = ft_lstnew(((*f)(cur))->content, ((*f)(cur))->content_size);
		ft_lstaddlast(&new, cpy);
		cur = cur->next;
	}
	return (new);
}
