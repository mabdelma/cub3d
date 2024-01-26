/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:01:43 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:01:44 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	player_rotation_reflection(t_mlx *mlx, t_rot rotation)
{
	double	*camera[2];
	double	*direction[2];
	double	old_direction[2];
	double	old_camera[2];
	double	angle_step[2];

	direction[X] = &mlx->player.direction[X];
	direction[Y] = &mlx->player.direction[Y];
	camera[X] = &mlx->player.camera_plane[X];
	camera[Y] = &mlx->player.camera_plane[Y];
	old_direction[X] = mlx->player.direction[X];
	old_direction[Y] = mlx->player.direction[Y];
	old_camera[X] = mlx->player.camera_plane[X];
	old_camera[Y] = mlx->player.camera_plane[Y];
	angle_step[SIN] = sin((ROTATE_ANGLE * 3.14) / 180.0F);
	angle_step[COS] = cos((ROTATE_ANGLE * 3.14) / 180.0F);
	*direction[X] = old_direction[X] * angle_step[COS]
		- (rotation * old_direction[Y]) * angle_step[SIN];
	*camera[X] = old_camera[X] * angle_step[COS]
		- (rotation * old_camera[Y]) * angle_step[SIN];
	*direction[Y] = (rotation * old_direction[X]) * angle_step[SIN]
		+ old_direction[Y] * angle_step[COS];
	*camera[Y] = (rotation * old_camera[X]) * angle_step[SIN]
		+ old_camera[Y] * angle_step[COS];
	ray_cast_main_func(mlx);
}

void	player_motion_reflection(int keycode, t_mlx *mlx)
{
	double	*pos[2];
	double	move[3];

	pos[X] = &mlx->player.pos[X];
	pos[Y] = &mlx->player.pos[Y];
	motion_axes_analysis(keycode, mlx, move);
	if (mlx->map->grid[(int)(*pos[Y] + move[Y])][(int)(*pos[X])] != WALL)
		*pos[Y] += move[Y];
	if (mlx->map->grid[(int)(*pos[Y])][(int)(*pos[X] + move[X])] != WALL)
		*pos[X] += move[X];
	ray_cast_main_func(mlx);
}

int	events_handling(int keycode, t_mlx *mlx)
{
	if (keycode == KEYCODE_ESC)
		mlx_closing(mlx);
	else if (keycode == KEYCODE_W || keycode == KEYCODE_A
		|| keycode == KEYCODE_S || keycode == KEYCODE_D)
		player_motion_reflection(keycode, mlx);
	else if (keycode == KEYCODE_L_ARROW)
		player_rotation_reflection(mlx, LEFT);
	else if (keycode == KEYCODE_R_ARROW)
		player_rotation_reflection(mlx, RIGHT);
	return (0);
}

void	motion_axes_analysis(int keycode, t_mlx *mlx, double *move)
{
	move[ANGLE] = atan2(mlx->player.direction[Y], mlx->player.direction[X]);
	if (keycode == KEYCODE_W)
	{
		move[Y] = MOVE * sin(move[ANGLE]);
		move[X] = MOVE * cos(move[ANGLE]);
	}
	else if (keycode == KEYCODE_S)
	{
		move[Y] = -1 * (MOVE * sin(move[ANGLE]));
		move[X] = -1 * (MOVE * cos(move[ANGLE]));
	}
	else if (keycode == KEYCODE_A)
	{
		move[X] = MOVE * sin(move[ANGLE]);
		move[Y] = -1 * (MOVE * cos(move[ANGLE]));
	}
	else if (keycode == KEYCODE_D)
	{
		move[X] = -1 * (MOVE * sin(move[ANGLE]));
		move[Y] = MOVE * cos(move[ANGLE]);
	}
}
