/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:11:14 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:12:19 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ray_cast_step_setting(const double *pos, t_dda *dda)
{
	if (dda->ray[X] < 0)
	{
		dda->step[X] = -1;
		dda->next_hit[V] = (pos[X] - dda->map_cell[X]) * dda->delta[V];
		dda->side[V] = WE;
	}
	else
	{
		dda->step[X] = 1;
		dda->next_hit[V] = (dda->map_cell[X] + 1 - pos[X]) * dda->delta[V];
		dda->side[V] = EA;
	}
	if (dda->ray[Y] < 0)
	{
		dda->step[Y] = -1;
		dda->next_hit[H] = (pos[Y] - dda->map_cell[Y]) * dda->delta[H];
		dda->side[H] = SO;
	}
	else
	{
		dda->step[Y] = 1;
		dda->next_hit[H] = (dda->map_cell[Y] + 1 - pos[Y]) * dda->delta[H];
		dda->side[H] = NO;
	}
}

void	ray_cast_parameters_setting(t_dda *dda, const t_player *player,
	const int *slice, const double normalized_camera_factor)
{
	double	camera_x_pos;

	camera_x_pos = (*slice * normalized_camera_factor) - 1;
	dda->ray[X] = player->direction[X]
		+ (player->camera_plane[X] * camera_x_pos);
	dda->ray[Y] = player->direction[Y]
		+ (player->camera_plane[Y] * camera_x_pos);
	if (dda->ray[X])
		dda->delta[V] = fabs(1 / dda->ray[X]);
	else
		dda->delta[V] = VERY_BIG_NUMBER;
	if (dda->ray[Y])
		dda->delta[H] = fabs(1 / dda->ray[Y]);
	else
		dda->delta[H] = VERY_BIG_NUMBER;
}

t_texture	ray_cast_dda(t_dda *dda, const t_map *map)
{
	int			current_grid[2];

	current_grid[X] = dda->map_cell[X];
	current_grid[Y] = dda->map_cell[Y];
	while (true)
	{
		if (dda->next_hit[V] < dda->next_hit[H])
		{
			dda->next_hit[V] += dda->delta[V];
			current_grid[X] += dda->step[X];
			dda->hit = dda->side[V];
		}
		else
		{
			dda->next_hit[H] += dda->delta[H];
			current_grid[Y] += dda->step[Y];
			dda->hit = dda->side[H];
		}
		if (map->grid[current_grid[Y]][current_grid[X]] == WALL)
			break ;
	}
	return (dda->hit);
}

void	ray_cast_main_func(t_mlx *mlx)
{
	t_dda		dda;
	t_texture	hit;
	int			slice;
	double		normalized_camera_factor;

	slice = 0;
	normalized_camera_factor = 2 / (double)WIN_WIDTH;
	dda.map_cell[X] = (int)mlx->player.pos[X];
	dda.map_cell[Y] = (int)mlx->player.pos[Y];
	window_background_filling(mlx);
	while (slice < WIN_WIDTH)
	{
		ray_cast_parameters_setting(&dda, &mlx->player, &slice, normalized_camera_factor);
		ray_cast_step_setting(mlx->player.pos, &dda);
		hit = ray_cast_dda(&dda, mlx->map);
		if (hit == dda.side[H])
			dda.distance_to_wall = dda.next_hit[H] - dda.delta[H];
		else
			dda.distance_to_wall = dda.next_hit[V] - dda.delta[V];
		set_slice(mlx, &dda, slice);
		slice++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
		mlx->img_data.img_ptr, 0, 0);
}
