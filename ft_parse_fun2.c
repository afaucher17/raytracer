/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fun2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:20:45 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/22 19:03:56 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"raytracer.h"

int				ft_get_value(t_list **list)
{
	int			res;

	res = 0;
	if (*list)
	{
		res = ft_atoi((*list)->content);
		*list = (*list)->next;
	}
	return (res);
}

void			ft_fillellipse(t_list **list, t_obj **olist)
{
	t_ellipse	*ellipse;
	t_obj		*obj;

	ellipse = ft_ellipsenew(ft_get_point(list), ft_get_vect(list),
							ft_get_vect(list), ft_get_value(list));
	obj = ft_objnew(ellipse, O_ELLIPSOID, ft_get_color(list));
	ft_objaddfront(olist, obj);
	obj->spec = ft_get_value(list) / 100.0;
}

t_point			*ft_get_point(t_list **list)
{
	t_point		*point;

	point = ft_pointnew(ft_get_value(list), ft_get_value(list),
						ft_get_value(list));
	return (point);
}

t_vect			*ft_get_vect(t_list **list)
{
	t_vect		*vect;

	vect = ft_vectornew(ft_get_value(list),
						ft_get_value(list),
						ft_get_value(list));
	return (vect);
}

t_color			*ft_get_color(t_list **list)
{
	t_color		*color;

	color = ft_colornew(ft_get_value(list),
						ft_get_value(list),
						ft_get_value(list));
	return (color);
}
