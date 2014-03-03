/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 13:28:15 by afaucher          #+#    #+#             */
/*   Updated: 2014/01/16 13:13:45 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H
# define PI 3.14159265359
# define RAD(degree) ((PI * degree) / 180)
# define ALEFT(angle) (angle >= PI / 2 && angle < 3 * PI / 2)
# define ARIGHT(angle) !ALEFT(angle)
# define AUP(angle) (angle < PI)
# define ADOWN(angle) !AUP(angle)
double	ft_pow(double nb, int p);
double	ft_abs(double nb);
long	ft_fact(long nb);
double	ft_getrad(double rad);
double	ft_cos(double rad);
double	ft_sin(double rad);
double	ft_tan(double rad);
#endif /* MATHS_H */
