/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:10:26 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:10:46 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

#ifdef __LINUX__

static void	*error_exiting_function(t_mlx *mlx, char *error_message)
{
	if (mlx->map && mlx->img_data.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_data.img_ptr);
	if (mlx->window)
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	if (mlx->map)
		map_deleting(mlx->map);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	free(mlx);
	if (error_message)
		write_error_msg(error_message);
	return (NULL);
}

#elif __APPLE__

static void	*error_exiting_function(t_mlx *mlx, char *error_message)
{
	if (mlx->map && mlx->img_data.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_data.img_ptr);
	if (mlx->window)
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	if (mlx->map)
		map_deleting(mlx->map);
	if (mlx->mlx_ptr)
		free(mlx->mlx_ptr);
	free(mlx);
	if (error_message)
		write_error_msg(error_message);
	return (NULL);
}
#endif

t_mlx	*mlx_data_initialization(char *map_path)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (write_error_msg(MEMORY_ALLOC_ERROR), NULL);
	mlx->map = map_loading(map_path);
	if (!mlx->map)
		return (NULL);
	if (!grid_general_validation(mlx->map, &mlx->player))
		return (error_exiting_function(mlx, NULL));
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (error_exiting_function(mlx, MLX_LIBRARY_INITIALIZATION));
	if (!textures_loading(mlx))
		return (error_exiting_function(mlx, NULL));
	mlx->window = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			WIN_TITLE);
	if (!mlx->window)
		return (error_exiting_function(mlx, WINDOW_START_ERROR));
	mlx->img_data = image_creation(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img_data.addr)
		return (error_exiting_function(mlx, IMAGE_CREATE_ERROR));
	return (mlx);
}

t_img	image_creation(void *mlx_ptr, int width, int height)
{
	t_img	image;

	image.img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (!image.img_ptr)
		return ((t_img){0});
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp,
			&image.line_length, &image.endian);
	return (image);
}
