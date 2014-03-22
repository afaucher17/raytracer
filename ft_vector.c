/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 18:38:34 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/22 15:09:14 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vect		*ft_vectornew(double x, double y, double z)
{
	t_vect	*new;

	if ((new = (t_vect*)malloc(sizeof(t_vect))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	ft_normalize(new);
	return (new);
}

double		ft_normalize(t_vect *vect)
{
	double	norme;

	norme = sqrt(pow(vect->x, 2) + pow(vect->y, 2) + pow(vect->z, 2));
	if (norme)
	{
		vect->x /= norme;
		vect->y /= norme;
		vect->z /= norme;
	}
	return (norme);
}

t_vect		*ft_crossproduct(t_vect *v1, t_vect *v2)
{
	t_vect	*res;

	if ((res = ft_vectornew(0, 0, 0)) == NULL)
		return (NULL);
	res->x = (v1->y * v2->z) - (v2->y * v1->z);
	res->y = (v1->z * v2->x) - (v2->z * v1->x);
	res->z = (v1->x * v2->y) - (v2->x * v1->y);
	ft_normalize(res);
	return (res);
}

double		ft_getangle(t_vect *v1, t_vect *v2)
{
	double	cosa;

	cosa = (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
	return (cosa);
}

t_vect		*ft_getdirvector(t_point *vpupleft, t_camera *camera,
								double x, double y)
{
	t_vect	*res;

	if ((res = ft_vectornew(0, 0, 0)) == NULL)
		return (NULL);
	res->x = -camera->origin->x + vpupleft->x + camera->right->x * X_INDENT * x
			- camera->up->x * Y_INDENT * y;
	res->y = -camera->origin->y + vpupleft->y + camera->right->y * X_INDENT * x
			- camera->up->y * Y_INDENT * y;
	res->z = -camera->origin->z + vpupleft->z + camera->right->z * X_INDENT * x
			- camera->up->z * Y_INDENT * y;
	ft_normalize(res);
	return (res);
}
