/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:25:08 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/10 11:58:32 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *begin_list, int (*cmp)())
{
	t_list	*elem1;
	t_list	*elem2;

	elem1 = begin_list;
	while (elem1)
	{
		elem2 = elem1->next;
		while (elem2)
		{
			if ((*cmp)(elem1->content, elem2->content) > 0)
				ft_lstswap(elem1, elem2);
			elem2 = elem2->next;
		}
		elem1 = elem1->next;
	}
}
