/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 16:07:00 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/22 20:54:38 by afaucher         ###   ########.fr       */
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
	double		ret;
	int			i;

	vect = ft_get_lvect(llist, point);
	dist = ft_get_dis(llist, point);
	while (olist)
	{
		i = 0;
		while (olist != minobj && i < OBJ_SIZE)
		{
			if (g_objtab[i].type == olist->type
				&& ((ret = g_objtab[i].f_inter(olist->obj, point, vect)) > 0)
				&& ret < dist)
				return (NULL);
			i++;
		}
		olist = olist->next;
	}
	return (vect);
}

int				ft_reflection(t_line *line, t_scene *scene, t_obj *obj, int depth)
{
	t_vect		*normal;
	double		cosa;
	int			i;
	int			color;

	i = 0;
	color = 0;
	while (i < OBJ_SIZE)
	{
		if (g_objtab[i].type == obj->type)
			normal = g_objtab[i].f_getnorm(obj->obj, line->origin, line->dir);
		i++;
	}
	cosa = ft_getangle(line->dir, normal);
	line->dir->x = -cosa * line->dir->x;
	line->dir->y = -cosa * line->dir->y;
	line->dir->z = -cosa * line->dir->z;
	if (depth > 0)
		color = ft_getinter(scene, line->origin, line->dir, depth - 1, obj);
	(((u_char*)&color)[0]) *= 0.5;
	(((u_char*)&color)[1]) *= 0.5;
	(((u_char*)&color)[2]) *= 0.5;
	return (color);
}

int				ft_getlight(t_obj *minobj, t_scene *scene,
							t_line *lineo, int depth)
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
		if ((vect = ft_get_shadow(minobj, scene->objs,
									llist, lineo->origin)) != NULL)
		{
			line.dir = vect;
			line.origin = lineo->origin;
			color = ft_lightcolor(minobj, llist, &line, lineo->dir);
			ft_addcolor(final_color, color);
		}
		llist = llist->next;
	}
	ft_addcolor(final_color, ft_reflection(lineo, scene, minobj, depth));
	return (ft_colorstoi(final_color));
}
