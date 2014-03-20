/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 16:07:00 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/20 15:57:39 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static t_vect	*ft_get_lvect(t_light *llist, t_point *point)
{
	t_vect		*vect;

	vect = ft_vectornew(llist->point->x - point->x,
						llist->point->y - point->y,
						llist->point->z - point->z);
	return (vect);
}

static double	ft_get_dis(t_light *llist, t_point *point)
{
	double		dist;

	dist = sqrt(pow(llist->point->x - point->x, 2)
				+ pow(llist->point->y - point->y, 2)
				+ pow(llist->point->z - point->z, 2));
	return (dist);
}

static t_vect	*ft_get_shadow(t_obj *minobj, t_obj *olist,
						t_light *llist, t_point *point)
{
	double		dist;
	t_vect		*vect;
	int			i;

	vect = ft_get_lvect(llist, point);
	dist = ft_get_dis(llist, point);
	while (olist)
	{
		i = 0;
		while (olist != minobj && i < OBJ_SIZE)
		{
			if (g_objtab[i].type == olist->type
				&& g_objtab[i].f_inter(olist->obj, point, vect) > 0
				&& g_objtab[i].f_inter(olist->obj, point, vect) < dist)
				return (NULL);
			i++;
		}
		olist = olist->next;
	}
	return (vect);
}

int				ft_getlight(t_obj *minobj, t_scene *scene,
							t_point *point, t_vect *dir)
{
	t_color		*final_color;
	int			color;
	t_vect		*vect;
	t_light		*llist;
	t_line		line;

	llist = scene->lights;
	final_color = ft_colornew(0, 0, 0);
	while (llist)
	{
		if ((vect = ft_get_shadow(minobj, scene->objs, llist, point)) != NULL)
		{
			line.dir = vect;
			line.origin = point;
			color = ft_lightcolor(minobj, llist, &line, dir);
			final_color->r += (((u_char*)&color)[0]);
			final_color->g += (((u_char*)&color)[1]);
			final_color->b += (((u_char*)&color)[2]);
		}
		llist = llist->next;
	}
	final_color->r = (final_color->r > 255) ? 255 : final_color->r;
	final_color->g = (final_color->g > 255) ? 255 : final_color->g;
	final_color->b = (final_color->b > 255) ? 255 : final_color->b;
	return (ft_colorstoi(final_color));
}
