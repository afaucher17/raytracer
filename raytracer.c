/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:43:30 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/25 20:34:11 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <pthread.h>

static int		expose_hook(t_env *env)
{
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

static int		pthread_init(pthread_t *thread,
								t_mlx_img *img, t_scene *scene, int quarter)
{
	t_env		*env;

	if ((env = (t_env*)malloc(sizeof(t_env))) == NULL)
		return (0);
	env->xstart = quarter;
	env->scene = scene;
	env->img = img;
	printf("thread created %d\n", quarter);
	if (pthread_create(thread, NULL, ft_raytracer, env))
	{
		perror("raytracer: ");
		exit(EXIT_FAILURE);
	}
	return (1);
}

static int		pthread_manage(t_mlx_img *img, t_scene *scene)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;

	pthread_init(&thread1, img, scene, 0);
	pthread_init(&thread2, img, scene, 1);
	pthread_init(&thread3, img, scene, 2);
	pthread_init(&thread4, img, scene, 3);
	if (pthread_join(thread1, NULL) || pthread_join(thread2, NULL)
			|| pthread_join(thread3, NULL) || pthread_join(thread4, NULL))
	{
		perror("raytracer: ");
		exit(EXIT_FAILURE);
	}
	return (1);
}

void			raytracer(int fd)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_env		env;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, SIZE_X, SIZE_Y, "raytracer");
	env.img = create_img(mlx_ptr, win_ptr, SIZE_X, SIZE_Y);
	env.scene = ft_scenenew(fd);
	pthread_manage(env.img, env.scene);
	mlx_expose_hook(win_ptr, expose_hook, &env);
	mlx_key_hook(win_ptr, key_hook, &env);
	mlx_loop(mlx_ptr);
}
