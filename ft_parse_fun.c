/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:20:29 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/19 14:08:58 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"raytracer.h"

void			ft_fillplane(t_list **list, t_obj **olist)
{
	t_plane		*plane;

	plane = ft_planenew(ft_get_vect(list), ft_get_point(list));
	ft_objpushfront(olist, plane, O_PLANE, ft_get_color(list));
}

void			ft_fillsphere(t_list **list, t_obj **olist)
{
	int			i;
	t_sphere	*sphere;

	sphere = ft_spherenew(ft_atoi((*list)->content),
			ft_atoi((*list)->next->content),
			ft_atoi((*list)->next->next->content),
			ft_atoi((*list)->next->next->next->content));
	i = 0;
	while (i++ < 4)
		*list = (*list)->next;
	ft_objpushfront(olist, sphere, O_SPHERE, ft_get_color(list));
}

void			ft_fillcylinder(t_list **list, t_obj **olist)
{
	t_cylinder	*cylinder;

	cylinder = ft_cylindernew(ft_get_point(list),
								ft_get_vect(list), ft_atoi((*list)->content));
	*list = (*list)->next;
	ft_objpushfront(olist, cylinder, O_CYLINDER, ft_get_color(list));
}

void			ft_fillcone(t_list **list, t_obj **olist)
{
	t_cone		*cone;

	cone = ft_conenew(ft_get_point(list),
						ft_get_vect(list), ft_atoi((*list)->content),
						(ft_atoi((*list)->next->content) / 180.0) * M_PI);
	*list = (*list)->next;
	*list = (*list)->next;
	ft_objpushfront(olist, cone, O_CONE, ft_get_color(list));
}
