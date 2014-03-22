/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 19:12:49 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/22 20:32:49 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <sys/types.h>

enum				e_obj
{
	O_SPHERE,
	O_PLANE,
	O_CYLINDER,
	O_CONE,
	O_CUBE,
	O_ELLIPSOID,
	O_UNDEFINED
};

enum				e_light
{
	L_OMNI,
	L_SPOT,
	L_RAY
};

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef t_point		t_vect;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_sphere
{
	t_point			*center;
	double			radius;
}					t_sphere;

typedef struct		s_plane
{
	t_vect			*vect;
	t_point			*point;
	double			d;
}					t_plane;

typedef struct		s_cylinder
{
	t_point			*center;
	t_vect			*axis;
	double			radius;
	double			rot[4][4];
}					t_cylinder;

typedef struct		s_cone
{
	t_point			*center;
	t_vect			*axis;
	double			radius;
	double			angle;
	double			rot[4][4];
}					t_cone;

typedef struct		s_ellipse
{
	t_point			*center;
	t_vect			*axis;
	t_vect			*ray;
	double			radius;
	double			rot[4][4];
}					t_ellipse;

typedef struct		s_obj
{
	void			*obj;
	enum e_obj		type;
	t_color			*color;
	double			spec;
	double			refl;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_objfun
{
	char			*name;
	enum e_obj		type;
	t_vect			*(*f_getnorm)(void *, t_point *, t_vect *);
	double			(*f_inter)(void *, t_point *, t_vect *);
	void			(*f_clear)(void **);
	void			(*f_fill)(t_list **llist, t_obj **olist);
}					t_objfun;

typedef struct		s_line
{
	t_vect			*dir;
	t_point			*origin;
}					t_line;

typedef struct		s_camera
{
	t_point			*origin;
	t_vect			*dir;
	t_vect			*up;
	t_vect			*right;
}					t_camera;

typedef struct		s_light
{
	t_point			*point;
	t_color			*color;
	enum e_light	type;
	struct s_light	*next;
}					t_light;

typedef struct		s_scene
{
	t_camera		*camera;
	t_point			*vpupleft;
	t_obj			*objs;
	t_light			*lights;
}					t_scene;

typedef struct		s_mlx_img
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				height;
	int				width;
	int				size;
	int				endian;
}					t_mlx_img;

typedef struct		s_env
{
	t_mlx_img		*img;
	t_scene			*scene;
	int				xstart;
}					t_env;
#endif /* !STRUCT_H */
