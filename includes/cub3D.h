/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:00 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:20:40 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include "keycodes.h"

# ifdef __LINUX__
#  include <X11/keysym.h>
# endif

# define X 0
# define Y 1
# define STEP 2
# define COLOR 3
# define H 0
# define V 1
# define SUCCESS 1
# define FAILURE 0
# define NOT_SET -1
#define COLOR_START 2
#define PATH_START 3
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define WIN_TITLE "cub3D"
# define MAP_INITIAL_CAPACITY 5
# define DOUBLE 2
# define ACCEPTED_CHARACTERS "10VNSWE\n "
# define PLAYER_DIRECTIONS "NSWE"
# define WALL '1'
# define VERY_BIG_NUMBER 453211111.0f
# define MOVE 0.05f
# define ROTATE_ANGLE 2


# define COLOR_SET_ERROR "cannot set the color properly"
# define ARGS_COUNT_ERROR "please enter only one argument which is the map file"
# define PLAYER_COUNT_ERROR "number of players is invalid"
# define MAP_CHARACTER_ERROR "we get an invalid character in your map"
# define IMAGE_CREATE_ERROR "cannot create the image"
# define FILE_OPEN_FAILURE "cannot open the file"
# define MAP_CLOSING_ERROR "cannot close the map"
# define MEMORY_ALLOC_ERROR "cannot allocate the memory"
# define FILE_EXTENSION_ERROR "cannot find the file extension"
# define WINDOW_START_ERROR "cannot start the mlx window"
# define TEXTURE_LOAD_FAILURE "cannot load the texture"
# define MLX_LIBRARY_INITIALIZATION "cannot initialize the mlx"
# define SCENE_LOAD_FAILURE "cannot load the scene"


typedef enum e_texture
{
	NO = 0,
	WE,
	EA,
	SO,
	TOTAL_TEXTURES
}	t_texture;

typedef struct s_dda
{
	int			map_cell[2];
	double		ray[2];
	double		delta[2];
	double		next_hit[2];
	double		step[2];
	double		distance_to_wall;
	t_texture	hit;
	t_texture	side[2];
}	t_dda;

typedef struct s_player
{
	double	pos[2];
	double	direction[2];
	double	camera_plane[2];
}	t_player;

typedef enum e_map_color
{
	R = 0,
	G,
	B,
	TOTAL_COLORS
}	t_map_color;

typedef struct s_map
{
	char	**grid;
	int		n_rows;
	int		grid_capacity;
	char	*texture[TOTAL_TEXTURES];
	int		f_color[TOTAL_COLORS];
	int		c_color[TOTAL_COLORS];
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		img_width;
	int		img_height;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx {
	void		*mlx_ptr;
	void		*window;
	t_img		textures[TOTAL_TEXTURES];
	t_img		img_data;
	t_map		*map;
	t_player	player;
}	t_mlx;

typedef enum e_slice
{
	TOP = 0,
	BOT,
	HEIGHT
}	t_slice;

typedef enum e_rot
{
	LEFT = -1,
	RIGHT = 1
}	t_rot;

typedef enum e_movement
{
	SIN = 0,
	COS,
	ANGLE
}	t_movement;

int		return_success(void);
int		events_handling(int keycode, t_mlx *mlx_core);
int		mlx_closing(t_mlx *mlx_core);
void	my_pixel_put(t_img *image, int x, int y, int color);
void	map_deleting(t_map *map);
int		write_error_msg(char *error_msg);
void	motion_axes_analysis(int keycode, t_mlx *mlx, double *move);
t_map	*map_loading(char *map_path);
int		grid_loading(t_map *map, int map_fd, char **current_map_row);
int		scene_loading(t_map *map, int map_fd, char **current_map_row);
int		scene_color_validation(char *color_string);
char	*texture_id_getting(char *current_map_row);
char	*next_row_validation(int map_fd);
bool	map_extension_check(char *map_path, char *target);
void	*map_items_deleting(char *current_map_row, int map_fd, t_map *map);
t_map	*grid_general_validation(t_map *map, t_player *player);
void	set_slice(t_mlx *mlx, t_dda *dda, int slice);
void	window_background_filling(t_mlx *mlx);
void	ray_cast_main_func(t_mlx *mlx);
t_mlx	*mlx_data_initialization(char *map_path);
int		scene_color_verification(t_map *map);
bool	empty_row_checking(char *current_map_row);
bool	extensions_checking(char *map_path, char *target);
void	empty_gnl(char *current_map_row, int map_fd);
bool	textures_loading(t_mlx *mlx);
t_img	image_creation(void *mlx_ptr, int width, int height);
bool	grid_closing_verification(const t_map *map, const int x, const int y);
bool	grid_characters_verification(t_map *map, t_player *player);
void	grid_add_player(t_player *player, int x, int y, char view_direction);
void	column_height_calculation(double *col, int max_height, double dist_to_wall);
bool	set_texture_color(t_mlx *mlx, t_dda *dda, double *texel, double *column);
unsigned int	get_texture_color(t_img *img, int x, int y, bool dark);
int	grid_reflection(t_map *map);
int	grid_add_new_row(char *current_map_row, t_map *map);
t_map	*map_initialization(void);
void	map_color_initialization(t_map *map);
void	ray_cast_step_setting(const double *pos, t_dda *dda);
void	ray_cast_parameters_setting(t_dda *dda, const t_player *player,
	const int *slice, const double normalized_camera_factor);
t_texture	ray_cast_dda(t_dda *dda, const t_map *map);
int	scene_colors_assigning(int *map_color, char *current_map_row);
bool	scene_texture_assigning(char **texture, char *current_map_row);
int	scene_parameters_setting(t_map *map, char *texture_id, char *current_map_row);


#endif
