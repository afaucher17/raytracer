/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:55:42 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/01 16:24:04 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *elem1, t_list *elem2)
{
	void	*content;
	size_t	content_size;

	if (elem1 && elem2)
	{
		content = elem1->content;
		content_size = elem1->content_size;
		elem1->content = elem2->content;
		elem1->content_size = elem2->content_size;
		elem2->content = content;
		elem2->content_size = content_size;
	}
}
