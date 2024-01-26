/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:15:43 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:15:44 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	set_color_setting(int map_color[TOTAL_COLORS])
{
	return ((map_color[R] << 16 | map_color[G] << 8 | map_color[B]));
}

void	window_background_filling(t_mlx *mlx)
{
	int		current_color;
	int		ceiling_color;
	int		floor_color;
	int		y;
	int		x;

	ceiling_color = set_color_setting(mlx->map->c_color);
	floor_color = set_color_setting(mlx->map->f_color);
	current_color = ceiling_color;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			my_pixel_put(&mlx->img_data, x++, y, current_color);
		if (y >= WIN_HEIGHT / 2)
			current_color = floor_color;
		y++;
	}
}
