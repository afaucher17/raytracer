/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:20:29 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/26 11:59:29 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"raytracer.h"

void			ft_fillplane(t_list **list, t_obj **olist)
{
	t_plane		*plane;
	t_obj		*obj;

	plane = ft_planenew(ft_get_vect(list), ft_get_point(list));
	obj = ft_objnew(plane, O_PLANE, ft_get_color(list));
	ft_objaddfront(olist, obj);
	obj->spec = ft_get_value(list) / 100.0;
}

void			ft_fillsphere(t_list **list, t_obj **olist)
{
	t_sphere	*sphere;
	t_obj		*obj;

	sphere = ft_spherenew(ft_get_value(list),
			ft_get_value(list),
			ft_get_value(list),
			ft_get_value(list));
	obj = ft_objnew(sphere, O_SPHERE, ft_get_color(list));
	ft_objaddfront(olist, obj);
	obj->spec = ft_get_value(list) / 100.0;
}

void			ft_fillcylinder(t_list **list, t_obj **olist)
{
	t_cylinder	*cylinder;
	t_obj		*obj;

	cylinder = ft_cylindernew(ft_get_point(list),
								ft_get_vect(list), ft_get_value(list));
	obj = ft_objnew(cylinder, O_CYLINDER, ft_get_color(list));
	ft_objaddfront(olist, obj);
	obj->spec = ft_get_value(list) / 100.0;
}

void			ft_fillcone(t_list **list, t_obj **olist)
{
	t_cone		*cone;
	t_obj		*obj;

	cone = ft_conenew(ft_get_point(list),
						ft_get_vect(list), ft_get_value(list),
						(ft_get_value(list) / 180.0) * M_PI);
	obj = ft_objnew(cone, O_CONE, ft_get_color(list));
	ft_objaddfront(olist, obj);
	obj->spec = ft_get_value(list) / 100.0;
}
