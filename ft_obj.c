/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 18:22:09 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/27 16:14:08 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_objfun	g_objtab[OBJ_SIZE] =
{
	{"sphere", O_SPHERE, ft_normesphere, ft_intersphere,
		ft_clearsphere, ft_fillsphere},
	{"plane", O_PLANE, ft_normeplane, ft_interplane,
		ft_clearplane, ft_fillplane},
	{"cylinder", O_CYLINDER, ft_normecylinder, ft_intercylinder,
		ft_clearcylinder, ft_fillcylinder},
	{"cone", O_CONE, ft_normecone, ft_intercone, ft_clearcone, ft_fillcone},
	{"ellipsoid", O_ELLIPSOID, ft_normeellipse, ft_interellipse,
		ft_clearellipse, ft_fillellipse}
};

t_obj			*ft_objnew(void *obj, enum e_obj type, t_color *color)
{
	t_obj		*new;

	if ((new = (t_obj*)malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	new->obj = obj;
	new->type = type;
	new->next = NULL;
	new->color = color;
	new->spec = 0;
	new->refl = 0;
	new->refr = 0;
	new->opacity = 0;
	return (new);
}

void			ft_objaddfront(t_obj **list, t_obj *obj)
{
	t_obj		*cur;

	cur = *list;
	if (!cur)
		*list = obj;
	else
	{
		*list = obj;
		obj->next = cur;
	}
}

void			ft_objpushfront(t_obj **list, void *obj,
							enum e_obj type, t_color *color)
{
	t_obj		*cur;
	t_obj		*new;

	new = ft_objnew(obj, type, color);
	cur = *list;
	if (!cur)
		*list = new;
	else
	{
		*list = new;
		new->next = cur;
	}
}
