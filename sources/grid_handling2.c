/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_handling2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:03:12 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:04:21 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	grid_add_player(t_player *player, int x, int y, char view_direction)
{
	player->pos[X] = x + 0.5;
	player->pos[Y] = y + 0.5;
	if (view_direction == 'E')
	{
		player->direction[X] = 1;
		player->camera_plane[Y] = 0.66;
	}
	else if (view_direction == 'W')
	{
		player->direction[X] = -1;
		player->camera_plane[Y] = -0.66;
	}
	else if (view_direction == 'N')
	{
		player->direction[Y] = -1;
		player->camera_plane[X] = 0.66;
	}
	else if (view_direction == 'S')
	{
		player->direction[Y] = 1;
		player->camera_plane[X] = -0.66;
	}
	else
		write_error_msg(MAP_CHARACTER_ERROR);
}

bool	grid_characters_verification(t_map *map, t_player *player)
{
	int	x;
	int	y;
	int	player_count;

	player_count = 0;
	y = -1;
	while (++y < map->n_rows)
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (ft_strchr(PLAYER_DIRECTIONS, map->grid[y][x]))
			{
				grid_add_player(player, x, y, map->grid[y][x]);
				player_count++;
			}
			if (!ft_strchr(ACCEPTED_CHARACTERS, map->grid[y][x]))
				return (write_error_msg(MAP_CHARACTER_ERROR));
		}
	}
	if (player_count != 1)
		return (write_error_msg(PLAYER_COUNT_ERROR));
	return (true);
}

bool	grid_closing_verification(const t_map *map, const int x, const int y)
{
	char	*current_cell;

	if (x >= (int)ft_strlen(map->grid[y]) || x < 0 || y < 0 || y >= map->n_rows)
		return (FAILURE);
	current_cell = &map->grid[y][x];
	if (*current_cell == WALL || *current_cell == 'V')
		return (true);
	else if (*current_cell == '0'
		|| ft_strchr(PLAYER_DIRECTIONS, *current_cell))
		*current_cell = 'V';
	else if (x == 0 || *current_cell == '\n'
		|| ft_iswhitespace(*current_cell)
		|| y == 0 || y == map->n_rows - 1)
		return (FAILURE);
	if (!grid_closing_verification(map, x + 1, y) || !grid_closing_verification(map, x - 1, y)
		|| !grid_closing_verification(map, x, y + 1) || !grid_closing_verification(map, x, y - 1))
		return (FAILURE);
	return (true);
}

t_map	*grid_general_validation(t_map *map, t_player *player)
{
	if (!grid_characters_verification(map, player))
		map_deleting(map);
	if (!grid_closing_verification(map, player->pos[X], player->pos[Y]))
	{
		write_error_msg(MAP_CLOSING_ERROR);
		map_deleting(map);
	}
	return (map);
}
