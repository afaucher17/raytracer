/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:37:38 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/22 20:52:09 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "libft/libft.h"
# include "struct.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>

# define KEY_Z 122
# define KEY_X 120
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307
# define KEY_M 109

# define OBJ_SIZE 5

# define VP_WIDTH 0.5
# define VP_HEIGHT 0.35

# define VP_DIST 1.0
# define SIZE_X 1280.0
# define SIZE_Y 896.0
# define ANTIALIASING 4.0
# define NB_THREAD 4
# define X_INDENT VP_WIDTH / SIZE_X
# define Y_INDENT VP_HEIGHT / SIZE_Y

extern t_objfun	g_objtab[OBJ_SIZE];
/*
** raytracer.c
*/
void			raytracer(int fd);

/*
** ft_scene.c
*/
t_scene			*ft_scenenew(int fd);

/*
** ft_raytracer.c
*/
int				ft_getinter(t_scene *scene, t_point *origin,
							t_vect *vect, int depth, t_obj *minobj);
void			*ft_raytracer(void *ptr_env);

/*
** ft_point.c
*/
t_point			*ft_pointnew(double x, double y, double z);
int				pixel_to_img(t_mlx_img *img, int x, int y, int color);
size_t			get_pixel_at(t_mlx_img *img, int x, int y);
double			point_distance(t_point *p1, t_point *p2, double rad);
t_point			*ft_getvpupleft(t_camera *camera);

/*
** ft_obj.c
*/
t_obj			*ft_objnew(void *obj, enum e_obj type, t_color *color);
void			ft_objaddfront(t_obj **list, t_obj *obj);
void			ft_objpushfront(t_obj **list, void *obj,
								enum e_obj type, t_color *color);

/*
** ft_sphere.c
*/
t_sphere		*ft_spherenew(double x, double y, double z, double radius);
void			ft_clearsphere(void **sphere);
double			ft_getmin(double t1, double t2);
double			ft_intersphere(void *sphere, t_point *origin, t_vect *dir);
t_vect			*ft_normesphere(void *sphere, t_point *origin, t_vect *dir);

/*
** ft_cylinder.c
*/
t_cylinder		*ft_cylindernew(t_point *center, t_vect *axis, double radius);
void			ft_clearcylinder(void **cylinder);
double			ft_intercylinder(void *cylinder, t_point *origin, t_vect *dir);
t_vect			*ft_normecylinder(void *cylinder, t_point *origin, t_vect *dir);

/*
** ft_cone.c
*/
t_cone			*ft_conenew(t_point *center, t_vect *axis,
								double radius, double angle);
void			ft_clearcone(void **cone);
double			ft_intercone(void *cone, t_point *origin, t_vect *dir);
t_vect			*ft_normecone(void *cone, t_point *origin, t_vect *dir);

/*
** ft_ellipse.c
*/
t_ellipse		*ft_ellipsenew(t_point *center, t_vect *axis,
							t_vect *ray, double radius);
void			ft_clearellipse(void **ptr_ellipse);
double			ft_interellipse(void *ptr_ellipse, t_point *origin,
								t_vect *dir);
t_vect			*ft_normeellipse(void *ptr_ellipse, t_point *origin,
									t_vect *vect);

/*
** ft_vector.c
*/
t_vect			*ft_vectornew(double x, double y, double z);
double			ft_normalize(t_vect *vect);
t_vect			*ft_crossproduct(t_vect *v1, t_vect *v2);
double			ft_getangle(t_vect *v1, t_vect *v2);
t_vect			*ft_getdirvector(t_point *vpupleft, t_camera *camera,
								double x, double y);

/*
** ft_vector2.c
*/
double			ft_get_dot(t_vect *ldir, t_vect *norm, t_vect *dir);

/*
** ft_plane.c
*/
t_plane			*ft_planenew(t_vect *vect, t_point *point);
void			ft_clearplane(void **plane);
double			ft_interplane(void *plane, t_point *origin, t_vect *dir);
t_vect			*ft_normeplane(void *plane, t_point *origin, t_vect *dir);

/*
** ft_light.c
*/
t_light			*ft_lightnew(t_point *point, enum e_light type, t_color *color);
void			ft_lightclear(t_light **light);
void			ft_lightpushfront(t_light **light, t_point *point,
									enum e_light type, t_color *color);
int				ft_lightcolor(t_obj *obj, t_light *light,
								t_line *line, t_vect *dir);

/*
** ft_getlight.c
*/
int				ft_getlight(t_obj *minobj, t_scene *scene, t_line *line, int depth);

/*
** ft_color.c
*/
t_color			*ft_colornew(double r, double g, double b);
void			ft_addcolor(t_color *color, int colori);
int				ft_colorstoi(t_color *scolor);
int				ft_getcolor(t_obj *obj, t_color *lcolor,
							double cosa, double dot);

/*
** image.c
*/
t_mlx_img		*create_img(void *mlx_ptr, void *win_ptr,
							int width, int height);
t_mlx_img		*get_xpm_image(void *mlx_ptr, char *filename);
int				darken_color(int color, int bpp, char ratio);

/*
** ft_parser.c
*/
void			ft_parser(int fd, t_light **llist, t_obj **olist);

/*
** ft_parse_fun.c
*/
void			ft_fillsphere(t_list **list, t_obj **olist);
void			ft_fillplane(t_list **list, t_obj **olist);
void			ft_fillcylinder(t_list **list, t_obj **olist);
void			ft_fillcone(t_list **list, t_obj **olist);
void			ft_fillellipse(t_list **list, t_obj **olist);
int				ft_get_value(t_list **list);
t_point			*ft_get_point(t_list **list);
t_vect			*ft_get_vect(t_list **list);
t_color			*ft_get_color(t_list **list);

/*
** ft_matrix.c
*/
void			ft_get_rotate_matrix(double cosx, double cosy,
										double cosz, double rot[4][4]);
void			ft_get_translate_matrix(t_point *center, double rot[4][4]);
t_point			*ft_rotate_point(t_point *origin, t_point *center, double rot[4][4]);
t_vect			*ft_rotate_vect(t_vect *dir, double rot[4][4]);
#endif /* !RTV1_H */
