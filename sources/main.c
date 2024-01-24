/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:07:52 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:07:52 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*map_path;

	if (argc != 2)
		return (write_error_msg(ARGS_COUNT_ERROR));
	map_path = argv[1];
	mlx = mlx_data_initialization(map_path);
	if (!mlx)
		return (-1);
	ray_cast_main_func(mlx);
	mlx_loop_hook(mlx->mlx_ptr, return_success, mlx);
	mlx_hook(mlx->window, 2, 1L << 0, events_handling, mlx);
	mlx_hook(mlx->window, 17, 1L << 17, mlx_closing, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
