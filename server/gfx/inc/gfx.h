/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 15:33:15 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/10 19:36:25 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include <libft.h>
# include <math.h>
# include <ft_get_next_line.h>
# include <fcntl.h>
# include <stdio.h>
# include <glew.h>
# include <GLFW/glfw3.h>
# include <cimport.h>
# include <scene.h>
# include <postprocess.h>
# include <lodepng.h>

# define WIN_H 1024
# define WIN_W 1280
# define FOV 67.f
# define NEAR 0.1f
# define FAR 80.f
# define MAP_X 15
# define MAP_Y 15
# define TILE_X 1.5f
# define HALF_TILE TILE_X / 2
# define MAX_X 15
# define MIN_X -15
# define ALLOC_BUFFER 128
# define T 1
# define ASPECT (float)WIN_W / (float)WIN_H

typedef struct s_vector			t_vec;
typedef struct s_vec2			t_vec2;
typedef struct s_mat4			t_mat4;
typedef struct s_cam			t_cam;
typedef struct s_mouse			t_mouse;
typedef struct s_img			t_img;
typedef struct s_vao			t_vao;
typedef struct s_scene			t_scene;
typedef struct s_object			t_object;
typedef struct s_gldata			t_gldata;
typedef struct s_player			t_player;
typedef struct s_ressource		t_ressource;
typedef struct s_tile			t_tile;
typedef enum e_object_names		t_object_names;
typedef enum e_ressource_type	t_rtype;

struct	s_vector
{
	float	x;
	float	y;
	float	z;
};

struct	s_vec2
{
	int	x;
	int	y;
};

enum	e_object_names
{
	TILE = 0,
	SKYBOX = 1,
	PLAYER,
	ROCK,
	END,
};

enum	e_ressource_type
{
	FOOD = 0,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME
};

struct	s_mat4
{
	float	m[16];
};

struct	s_mouse
{
	float	lx;
	float	lz;
	float	angle;
	float	delta_angle;
	float	origin_x;
};

struct	s_cam
{
	int		change;
	t_vec	pos;
	float	yaw;
	float	yaw_speed;
	float	speed;
	float	y_dif;
	t_mat4	proj_matrix;
	t_mat4	view_matrix;
	int		view_mat_location;
	int		proj_mat_location;
};

struct s_img
{
	unsigned char	*data;
	int			x;
	int			y;
};

struct s_gldata
{
	GLuint	vao;
	GLuint	program;
	GLuint	texture;
	int		point_count;
};

struct	s_player
{
	int			id;
	int			moving;
	t_circ_lst	*ressources;
};

struct	s_ressource
{
	t_vec	pos_in_tile;
	t_rtype	type;
};

struct s_tile
{
	t_circ_lst	*players;
	t_circ_lst	*ressources;
};

struct s_scene
{
	int			object_count;
	t_gldata	*objects;
	int			map_x;
	int			map_y;
	t_tile		**map;
};

struct	s_object
{
	int			type;
	void		*obj;
	t_object	*next;
};

extern float	g_elapsed;
extern t_mouse	g_mouse;

t_vec		grid_to_world(int x, int y, int map_x, int map_y);
void		init_map(t_scene *scene, int x, int y);
int			load_scene(t_scene *scene, t_cam *cam);
void		translate_obj(GLuint shader_prog, t_vec pos, int type);
void		translate_cam(GLuint shader_prog, t_cam cam, int sky);
t_vec		new_vector(float x, float y, float z);
t_vec2		new_vec2(int x, int y);
void		draw_map(t_cam cam, t_scene scene);
t_gldata	set_particle(int particle_count, char *file);
void		draw_particles(t_gldata particle);
GLuint		get_shader(char *obj_name);
int			load_skybox(void);
int			read_png_file(char *file, t_img *img);
int			load_texture(char *file);
int			load_meshes(char *file, t_scene *scene, int index);
int			ft_error(char *msg);
void		mouse_move(GLFWwindow *window, double xpos, double ypos);
void		mouse_button(GLFWwindow *window, int button, int action, int mode);
void		init_cam(t_cam *cam);
void		update_view_cam(t_cam *cam, GLFWwindow *window);
void		print_shader_log(GLuint shader);
void		print_matrix(t_mat4 matrix);
void		scroll_function(GLFWwindow *window, double xoffset, double yoffset);
t_mat4		identity_matrix(void);
t_mat4		zero_matrix(void);
t_mat4		translation_matrix(t_vec p);
t_mat4		perspective_matrix(float fov, float aspect, float near, float far);
t_mat4		view_matrix(t_vec cam_pos, t_vec look_at, t_vec roll);
t_mat4		scale_matrix(t_vec p);
t_mat4		rot_x_matrix(float angle);
t_mat4		rot_y_matrix(float angle);
t_mat4		rot_z_matrix(float angle);
t_mat4		multiply_matrix(t_mat4 mat1, t_mat4 mat2);
t_vec		new_vector(float x, float y, float z);
t_vec		normalize(t_vec p);
t_vec		cross(t_vec a, t_vec b);
t_vec		sub_vector(t_vec a, t_vec b);
float		get_length(t_vec p);

#endif
