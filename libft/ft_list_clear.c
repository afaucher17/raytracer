/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:28:05 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/09 18:29:23 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"libft.h"

int				ft_list_clear(t_list **list)
{
	t_list		*next;

	while (*list)
	{
		next = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = next;
	}
	return (1);
}
