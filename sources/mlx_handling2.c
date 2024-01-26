/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:10:56 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:13:20 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

bool	textures_loading(t_mlx *mlx)
{
	char	*tex_path;
	void	**texture;
	char	**address;
	int		*dim[2];
	int		i;

	i = -1;
	while (++i < TOTAL_TEXTURES)
	{
		texture = &(mlx->textures[i].img_ptr);
		address = &(mlx->textures[i].addr);
		tex_path = mlx->map->texture[i];
		dim[0] = &mlx->textures[i].img_width;
		dim[1] = &mlx->textures[i].img_height;
		texture = mlx_xpm_file_to_image(mlx->mlx_ptr, tex_path, dim[0], dim[1]);
		if (!texture)
			return (write_error_msg(TEXTURE_LOAD_FAILURE));
		*address = mlx_get_data_addr(texture, &mlx->textures[i].bpp,
				&mlx->textures[i].line_length, &mlx->textures[i].endian);
		if (!address)
			return (write_error_msg(TEXTURE_LOAD_FAILURE));
	}
	return (true);
}

#ifdef __LINUX__

int	mlx_closing(t_mlx *mlx)
{
	int		i;
	t_map	*map;

	map = mlx->map;
	i = 0;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_data.img_ptr);
	while (i < TOTAL_TEXTURES && mlx->textures[i].img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->textures[i++].img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	map_deleting(map);
	return (SUCCESS);
}

#elif __APPLE__

int	mlx_closing(t_mlx *mlx)
{
	int		i;
	t_map	*map;

	map = mlx->map;
	i = 0;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_data.img_ptr);
	while (i < TOTAL_TEXTURES && mlx->textures[i].img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->textures[i++].img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	free(mlx->mlx_ptr);
	free(mlx);
	map_deleting(map);
	return (SUCCESS);
}
#endif
