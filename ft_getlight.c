/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 16:07:00 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/27 22:06:03 by afaucher         ###   ########.fr       */
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

static t_vect	*ft_get_shadow(t_obj *minobj, double *coeff,
						t_light *llist, t_point *point)
{
	double		dist;
	t_vect		*vect;
	t_obj		*olist;
	double		ret;
	int			i;

	*coeff = 1;
	olist = g_scene->objs;
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
				*coeff *= ((1 - olist->opacity) < 0) ? 0 : 1 - olist->opacity;
			i++;
		}
		olist = olist->next;
	}
	return (vect);
}

int				ft_getlight(t_obj *minobj, t_line *lineo, int depth)
{
	t_color		*final_color;
	t_vect		*vect;
	t_light		*llist;
	t_line		line;

	llist = g_scene->lights;
	final_color = ft_colornew(0, 0, 0);
	while (llist)
	{
		if ((vect = ft_get_shadow(minobj, &(line.coeff),
									llist, lineo->origin)) != NULL)
		{
			line.dir = vect;
			line.origin = lineo->origin;
			ft_addcolor(final_color, ft_lightcolor(minobj, llist, &line,
						lineo->dir));
		}
		llist = llist->next;
	}
	return (ft_fresnel(final_color, lineo, minobj, depth));
}
