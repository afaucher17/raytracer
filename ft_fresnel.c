/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fresnel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:04:51 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/27 16:11:15 by frale-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static t_vect	*ft_refr_vect(t_vect *normal, t_line *line, double refr)
{
	double		cosi;
	double		sint2;
	double		cost;
	t_vect		*vect;

	if ((vect = ft_vectornew(0, 0, 0)) == NULL)
		return (NULL);
	cosi = -ft_getangle(line->dir, normal);
	sint2 = refr * refr * (1.0 - cosi * cosi);
	if (sint2 > 1.0)
		return (NULL);
	cost = sqrt(1.0 - sint2);
	vect->x = refr * line->dir->x + (refr * cosi - cost) * normal->x;
	vect->y = refr * line->dir->y + (refr * cosi - cost) * normal->y;
	vect->z = refr * line->dir->z + (refr * cosi - cost) * normal->z;
	ft_normalize(vect);
	return (vect);
}

static int		ft_refraction(t_line *line, t_obj *obj)
{
	t_vect		*normal;
	t_vect		*vect;
	int			i;
	int			color;

	color = 0;
	i = -1;
	while (++i < OBJ_SIZE)
		if (g_objtab[i].type == obj->type)
			normal = g_objtab[i].f_getnorm(obj->obj, line->origin, line->dir);
	if ((vect = ft_refr_vect(normal, line, obj->refr)) == NULL)
		return (0);
	if (obj->refr > 0.0)
		color = ft_getinter(line->origin, vect, 0, obj);
	((u_char*)&color)[0] *= (obj->color->r / 255.0) * (1 - obj->refl);
	((u_char*)&color)[1] *= (obj->color->g / 255.0) * (1 - obj->refl);
	((u_char*)&color)[2] *= (obj->color->b / 255.0) * (1 - obj->refl);
	free(vect);
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
	double		inv;

	inv = obj->spec;
	color2 = ft_refraction(line, obj);
	color1 = ft_reflection(line, obj, depth);
	final_color->r += inv * (((u_char*)&color1)[0] + ((u_char*)&color2)[0]);
	final_color->g += inv * (((u_char*)&color1)[1] + ((u_char*)&color2)[1]);
	final_color->b += inv * (((u_char*)&color1)[2] + ((u_char*)&color2)[2]);
	return (ft_colorstoi(final_color));
}
