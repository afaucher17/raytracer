/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 18:06:48 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/06 17:12:12 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinv(t_list **begin_list)
{
	t_list	*cur;
	t_list	*new;

	cur = *begin_list;
	new = NULL;
	while (cur)
	{
		ft_lstadd(&new, ft_lstnew(cur->content, cur->content_size));
		cur = cur->next;
	}
	*begin_list = new;
}
