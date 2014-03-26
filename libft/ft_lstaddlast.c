/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 12:28:02 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/03/26 12:28:09 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void		ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list	*cur;

	cur = ft_lstlast(*alst);
	if (cur)
		cur->next = new;
	else
		*alst = new;
}
