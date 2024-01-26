/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:12:58 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:12:59 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_map	*map_initialization(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (write_error_msg(MEMORY_ALLOC_ERROR), NULL);
	map_color_initialization(map);
	map->grid_capacity = MAP_INITIAL_CAPACITY;
	map->grid = ft_calloc(map->grid_capacity + 1, sizeof(char *));
	if (!map->grid)
	{
		free(map);
		return (write_error_msg(MEMORY_ALLOC_ERROR), NULL);
	}
	return (map);
}

void	map_color_initialization(t_map *map)
{
	int	i;

	i = 0;
	while (i < TOTAL_COLORS)
		map->f_color[i++] = NOT_SET;
	i = 0;
	while (i < TOTAL_COLORS)
		map->c_color[i++] = NOT_SET;
}

t_map	*map_loading(char *map_path)
{
	t_map	*map;
	char	*current_map_row;
	int		map_fd;

	if (!extensions_checking(map_path, ".cub"))
		return (NULL);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (write_error_msg(FILE_OPEN_FAILURE), NULL);
	map = map_initialization();
	if (!map)
		return (close(map_fd), NULL);
	if (!scene_loading(map, map_fd, &current_map_row))
		return (map_items_deleting(current_map_row, map_fd, map));
	if (!grid_loading(map, map_fd, &current_map_row))
		return (map_items_deleting(current_map_row, map_fd, map));
	return (close(map_fd), map);
}

void	map_deleting(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < TOTAL_TEXTURES)
			free(map->texture[i++]);
		ft_freeall((void **)map->grid);
		free(map);
		map = NULL;
	}
	exit(FAILURE);
}

void	*map_items_deleting(char *current_map_row, int map_fd, t_map *map)
{
	empty_gnl(current_map_row, map_fd);
	close(map_fd);
	map_deleting(map);
	return (NULL);
}