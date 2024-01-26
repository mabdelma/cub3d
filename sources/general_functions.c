/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:17 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:02:18 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	write_error_msg(char *error_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	return (0);
}

void	my_pixel_put(t_img *image, int x, int y, int color)
{
	if (y >= 0 && x >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		*(unsigned int *)(image->addr + \
			(y * image->line_length + x * (image->bpp >> 3))) = color;
}

int	return_success(void)
{
	return (0);
}

void	empty_gnl(char *current_map_row, int map_fd)
{
	while (current_map_row)
	{
		free(current_map_row);
		current_map_row = get_next_line(map_fd);
	}
}
