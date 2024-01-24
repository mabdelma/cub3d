/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_handling1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:52 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:07:07 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	grid_reflection(t_map *map)
{
	char	**old_grid;
	int		row_index;

	row_index = 0;
	old_grid = map->grid;
	map->grid_capacity *= DOUBLE;
	map->grid = ft_calloc(map->grid_capacity + 1, sizeof(char *));
	if (!map->grid)
	{
		write_error_msg(MEMORY_ALLOC_ERROR);
		return (FAILURE);
	}
	while (row_index < map->n_rows)
	{
		map->grid[row_index] = old_grid[row_index];
		row_index++;
	}
	free(old_grid);
	return (SUCCESS);
}

int	grid_add_new_row(char *current_map_row, t_map *map)
{
	if (!current_map_row)
		return (FAILURE);
	if (map->n_rows == map->grid_capacity)
	{
		if (!grid_reflection(map))
			return (FAILURE);
	}
	map->grid[map->n_rows++] = current_map_row;
	return (SUCCESS);
}

int	grid_loading(t_map *map, int map_fd, char **current_map_row)
{
	while (*current_map_row)
	{
		if (!grid_add_new_row(*current_map_row, map))
			return (FAILURE);
		*current_map_row = get_next_line(map_fd);
	}
	return (SUCCESS);
}
