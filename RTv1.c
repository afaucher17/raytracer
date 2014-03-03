/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:56:34 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/16 13:44:56 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static int		expose_hook(t_env *env)
{
	ft_raytracer(env->img, env->scene);
	mlx_put_image_to_window(env->img->mlx_ptr, env->img->win_ptr
							, env->img->img_ptr, 0, 0);
	return (1);
}

static int		key_hook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

void			rtv1(int fd)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	if (!env)
		return ;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, SIZE_X, SIZE_Y, "RTv1");
	env->img = create_img(mlx_ptr, win_ptr, SIZE_X, SIZE_Y);
	env->scene = ft_scenenew(fd);
	ft_raytracer(env->img, env->scene);
	mlx_expose_hook(win_ptr, expose_hook, env);
	mlx_key_hook(win_ptr, key_hook, env);
	mlx_loop(mlx_ptr);
}
