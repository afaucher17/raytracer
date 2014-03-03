/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:41:05 by afaucher          #+#    #+#             */
/*   Updated: 2013/12/01 16:04:39 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list	*cur;

	cur = ft_lstlast(*alst);
	if (cur)
		cur->next = new;
	else
		*alst = new;
}
