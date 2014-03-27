/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fresnel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:04:51 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/27 14:02:32 by frale-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static double	ft_sint2(t_vect *normal, t_vec *dir, double refr)
{
	double		cosi;
	double		sint2;

	cosi = -ft_getangle(dir, normal);
	sint2 = refr * refr * (1.0 - cosi * cosi);
	return (sint2);
}

static int		ft_refraction(t_line *line, t_obj *obj)
{
	double		n;
	double		cosi;
	double		sint2;
	double		cost;
	t_vect		*normal;
	int			i;
	int			color;

	color = 0;
	i = -1;
	while (++i < OBJ_SIZE)
		if (g_objtab[i].type == obj->type)
			normal = g_objtab[i].f_getnorm(obj->obj, line->origin, line->dir);
	if (sint2 > 1.0)
		return (0);
	cost = sqrt(1.0 - sint2);
	line->dir->x = n * line->dir->x + (n * cosi - cost) * normal->x;
	line->dir->y = n * line->dir->y + (n * cosi - cost) * normal->y;
	line->dir->z = n * line->dir->z + (n * cosi - cost) * normal->z;
	ft_normalize(line->dir);
	if (obj->refr > 0.0)
		color = ft_getinter(line->origin, line->dir, 0, obj);
	return (color);
}

static int		ft_reflection(t_line *line, t_obj *obj, int depth)
{
	t_vect		*normal;
	double		cosa;
	int			i;
	int			color;
	t_color		*color2;

	i = -1;
	color = 0;
	color2 = obj->color;
	while (++i < OBJ_SIZE)
		if (g_objtab[i].type == obj->type)
			normal = g_objtab[i].f_getnorm(obj->obj, line->origin, line->dir);
	cosa = -ft_getangle(line->dir, normal);
	line->dir->x += 2 * cosa * normal->x;
	line->dir->y += 2 * cosa * normal->y;
	line->dir->z += 2 * cosa * normal->z;
	ft_normalize(line->dir);
	if (depth > 0 && obj->refl > 0.0)
		color = ft_getinter(line->origin, line->dir, depth - 1, obj);
	((u_char*)&color)[0] *= (obj->color->r / 255.0) * obj->refl;
	((u_char*)&color)[1] *= (obj->color->g / 255.0) * obj->refl;
	((u_char*)&color)[2] *= (obj->color->b / 255.0) * obj->refl;
	return (color);
}

int				ft_fresnel(t_color *final_color, t_line *line,
							t_obj *obj, int depth)
{
	int			color1;
	int			color2;

	color1 = ft_reflection(line, obj, depth);
	color2 = ft_refraction(line, obj, depth);
	final_color->r += ((u_char*)&color1)[0] + ((u_char*)&color2)[0];
	final_color->g += ((u_char*)&color1)[1] + ((u_char*)&color2)[1];
	final_color->b += ((u_char*)&color1)[2] + ((u_char*)&color2)[2];
	return (ft_colorstoi(final_color));
}
