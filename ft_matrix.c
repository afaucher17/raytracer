/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 19:51:01 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/24 13:32:58 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void			ft_get_rotate_matrix(double cosx, double cosy,
										double cosz, double mat[4][4])
{
	double		sinx;
	double		siny;
	double		sinz;

	sinx = sin(acos(cosx));
	siny = sin(acos(cosy));
	sinz = sin(acos(cosz));
	mat[0][0] = cosy * cosz;
	mat[0][1] = -cosy * sinz;
	mat[0][2] = -siny;
	mat[1][0] = -sinx * siny * cosz + cosx * sinz;
	mat[1][1] = sinx * siny * sinz + cosx * cosz;
	mat[1][2] = -sinx * cosy;
	mat[2][0] = cosx * siny * cosz + sinx * sinz;
	mat[2][1] = -cosx * siny * sinz + sinx * cosz;
	mat[2][2] = cosx * cosy;
}

void			ft_get_translate_matrix(t_point *center, double mat[4][4])
{
	mat[0][3] = mat[0][0] * center->x + mat[0][1] * center->y + mat[0][2] * center->z;
	mat[1][3] = mat[1][0] * center->x + mat[1][1] * center->y + mat[1][2] * center->z;
	mat[2][3] = mat[2][0] * center->x + mat[2][1] * center->y + mat[2][2] * center->z;
}

t_point			*ft_rotate_point(t_point *origin, t_point *center, double mat[4][4])
{
	t_point		*ret;

	if ((ret = ft_pointnew(0, 0, 0)) == NULL)
		return (NULL);
	ret->x = (origin->x - center->x) * mat[0][0] + (origin->y - center->y)
				* mat[0][1] + (origin->z - center->z) * mat[0][2];
	ret->y = (origin->x - center->x) * mat[1][0] + (origin->y - center->y)
				* mat[1][1] + (origin->z - center->z) * mat[1][2];
	ret->z = (origin->x - center->x) * mat[2][0] + (origin->y - center->y)
				* mat[2][1] + (origin->z - center->z) * mat[2][2];
	ret->x += center->x;
	ret->y += center->y;
	ret->z += center->z;
	return (ret);
}

t_vect			*ft_rotate_vect(t_vect *dir, double mat[4][4])
{
	t_vect		*ret;

	if ((ret = ft_vectornew(0, 0, 0)) == NULL)
		return (NULL);
	ret->x = dir->x * mat[0][0] + dir->y * mat[0][1] + dir->z * mat[0][2];
	ret->y = dir->x * mat[1][0] + dir->y * mat[1][1] + dir->z * mat[1][2];
	ret->z = dir->x * mat[2][0] + dir->y * mat[2][1] + dir->z * mat[2][2];
	ft_normalize(ret);
	return (ret);
}
