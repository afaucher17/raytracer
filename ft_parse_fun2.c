/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fun2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:20:45 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/19 14:06:47 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"raytracer.h"

t_point			*ft_get_point(t_list **list)
{
	int			i;
	t_point		*point;

	i = 0;
	point = ft_pointnew(ft_atoi((*list)->content),
			ft_atoi((*list)->next->content),
			ft_atoi((*list)->next->next->content));
	while (i < 3)
	{
		*list = (*list)->next;
		i++;
	}
	return (point);
}

t_vect			*ft_get_vect(t_list **list)
{
	int			i;
	t_vect		*vect;

	i = 0;
	vect = ft_vectornew(ft_atoi((*list)->content),
						ft_atoi((*list)->next->content),
						ft_atoi((*list)->next->next->content));

	while (i < 3)
	{
		*list = (*list)->next;
		i++;
	}
	return (vect);
}

t_color			*ft_get_color(t_list **list)
{
	int			i;
	t_color		*color;

	i = 0;
	color = ft_colornew(ft_atoi((*list)->content),
						ft_atoi((*list)->next->content),
						ft_atoi((*list)->next->next->content));
	while (i < 3)
	{
		*list = (*list)->next;
		i++;
	}
	return (color);
}
