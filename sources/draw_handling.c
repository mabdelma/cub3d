/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:01:33 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:05:49 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

unsigned int	get_texture_color(t_img *img, int x, int y, bool dark)
{
	unsigned int	current_color;

	if (y >= 0 && x >= 0 && x < img->img_width && y < img->img_height)
		current_color = *((unsigned int *)(img->addr
					+ (y * img->line_length + x * (img->bpp / 8))));
	if (dark)
		current_color = (current_color >> 1) & 8355711;
	return (current_color);
}

bool	set_texture_color(t_mlx *mlx, t_dda *dda, double *texel, double *column)
{
	double	wall_x;
	bool	dark;
	t_img	texture;

	texture = mlx->textures[dda->hit];
	texel[STEP] = 1.0 * texture.img_height / column[HEIGHT];
	if (dda->hit == NO || dda->hit == SO)
	{
		wall_x = mlx->player.pos[X] + dda->distance_to_wall * dda->ray[X];
		dark = false;
	}
	else
	{
		wall_x = mlx->player.pos[Y] + dda->distance_to_wall * dda->ray[Y];
		dark = true;
	}
	wall_x -= (int)wall_x;
	texel[X] = (int)(wall_x * (double)texture.img_width);
	texel[Y] = (double)((column[TOP] - (WIN_HEIGHT / 2) + column[HEIGHT] / 2)
			* texel[STEP]);
	if ((dda->hit == NO || dda->hit == SO) && dda->ray[Y] > 0)
		texel[X] = texture.img_width - texel[X] - 1;
	if ((dda->hit == WE || dda->hit == EA) && dda->ray[X] < 0)
		texel[X] = texture.img_width - texel[X] - 1;
	return (dark);
}

void	column_height_calculation(double *col, int max_height, double dist_to_wall)
{
	col[HEIGHT] = max_height / dist_to_wall;
	col[TOP] = (-col[HEIGHT] / 2) + (max_height / 2);
	if (col[TOP] < 0)
		col[TOP] = 0;
	col[BOT] = (col[HEIGHT] / 2) + (max_height / 2);
	if (col[BOT] >= max_height)
		col[BOT] = max_height - 1;
}

void	set_slice(t_mlx *mlx, t_dda *dda, int slice)
{
	double	column[3];
	bool	dark;
	double	texel[4];
	int		i;

	column_height_calculation(column, WIN_HEIGHT, dda->distance_to_wall);
	texel[X] = 0;
	texel[Y] = 0;
	dark = set_texture_color(mlx, dda, texel, column);
	i = column[TOP];
	while (i < column[BOT])
	{
		texel[COLOR] = get_texture_color(&mlx->textures[dda->hit], texel[X],
				texel[Y], dark);
		my_pixel_put(&mlx->img_data, slice, i, texel[COLOR]);
		texel[Y] += texel[STEP];
		i++;
	}
}
