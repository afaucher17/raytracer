/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 21:31:28 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/27 22:05:53 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_light		*ft_lightnew(t_point *point, enum e_light light, t_color *color)
{
	t_light	*new;

	if ((new = (t_light*)malloc(sizeof(t_light))) == NULL)
		return (NULL);
	new->point = point;
	new->color = color;
	new->type = light;
	new->next = NULL;
	return (new);
}

void		ft_lightclear(t_light **light)
{
	free((*light)->point);
	free(*light);
	*light = NULL;
}

void		ft_lightpushfront(t_light **list, t_point *point
								, enum e_light type, t_color *color)
{
	t_light	*new;

	new = ft_lightnew(point, type, color);
	if (!(*list))
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}

int			ft_lightcolor(t_obj	*obj, t_light *light,
							t_line *line, t_vect *dir)
{
	double	cosa;
	double	dot;
	t_vect	*normal;
	int		i;
	int		color;

	i = -1;
	if (line->coeff <= 0)
		return (0);
	while (++i < OBJ_SIZE)
		if (g_objtab[i].type == obj->type)
			normal = g_objtab[i].f_getnorm(obj->obj, line->origin, line->dir);
	cosa = ft_getangle(line->dir, normal);
	dot = ft_get_dot(line->dir, normal, dir);
	if (cosa <= 0)
		return (0x000000);
	color = ft_getcolor(obj, light->color, cosa, dot);
	((u_char*)&color)[0] *= line->coeff;
	((u_char*)&color)[1] *= line->coeff;
	((u_char*)&color)[2] *= line->coeff;
	return (color);
}
