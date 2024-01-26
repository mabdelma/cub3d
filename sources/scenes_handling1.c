/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_handling1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:39 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:15:12 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

bool	extensions_checking(char *map_path, char *target)
{
	char	*extension;

	if (!map_path)
		return (write_error_msg(FILE_EXTENSION_ERROR));
	extension = ft_strrchr(map_path, '.');
	if (!extension)
		return (write_error_msg(FILE_EXTENSION_ERROR));
	if (ft_strncmp(extension, target, ft_strlen(target)))
		return (write_error_msg(FILE_EXTENSION_ERROR));
	else
		return (true);
}

int	scene_colors_assigning(int *map_color, char *current_map_row)
{
	char	*color_string;
	char	**rgb_color_strings;
	int		i;
	int		status;

	i = -1;
	status = SUCCESS;
	color_string = ft_substr(current_map_row, COLOR_START,
			ft_strlen(current_map_row) - COLOR_START);
	if (!scene_color_validation(color_string))
		return (FAILURE);
	rgb_color_strings = ft_split(color_string, ',');
	while (++i < TOTAL_COLORS)
	{
		if (!rgb_color_strings[i])
			break ;
		map_color[i] = atoi(rgb_color_strings[i]);
		if (map_color[i] > 255 || map_color[i] < 0)
			status = FAILURE;
	}
	ft_freeall((void **)rgb_color_strings);
	free(color_string);
	if (status)
		free(current_map_row);
	return (status);
}

bool	scene_texture_assigning(char **texture, char *current_map_row)
{
	*texture = ft_substr(current_map_row, PATH_START,
			ft_strlen(current_map_row) - PATH_START);
	if (!extensions_checking(*texture, ".xpm"))
		return (FAILURE);
	free(current_map_row);
	if (*texture == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	scene_parameters_setting(t_map *map, char *texture_id, char *current_map_row)
{
	if (!ft_strncmp(texture_id, "NO", 2) && !map->texture[NO])
		return (scene_texture_assigning(&map->texture[NO], current_map_row));
	else if (!ft_strncmp(texture_id, "SO", 2) && !map->texture[SO])
		return (scene_texture_assigning(&map->texture[SO], current_map_row));
	else if (!ft_strncmp(texture_id, "WE", 2) && !map->texture[WE])
		return (scene_texture_assigning(&map->texture[WE], current_map_row));
	else if (!ft_strncmp(texture_id, "EA", 2) && !map->texture[EA])
		return (scene_texture_assigning(&map->texture[EA], current_map_row));
	else if (!ft_strncmp(texture_id, "F", 1) && map->f_color[0] == NOT_SET)
		return (scene_colors_assigning(map->f_color, current_map_row));
	else if (!ft_strncmp(texture_id, "C", 1) && map->c_color[0] == NOT_SET)
		return (scene_colors_assigning(map->c_color, current_map_row));
	else
		return (FAILURE);
}

int	scene_loading(t_map *map, int map_fd, char **current_map_row)
{
	char	*texture_id;

	while (true)
	{
		*current_map_row = next_row_validation(map_fd);
		if (!*current_map_row || !ft_isalpha(*current_map_row[0]))
			break ;
		texture_id = texture_id_getting(*current_map_row);
		if (!texture_id)
			return (write_error_msg(SCENE_LOAD_FAILURE));
		if (!scene_parameters_setting(map, texture_id, *current_map_row))
		{
			free(texture_id);
			return (write_error_msg(SCENE_LOAD_FAILURE));
		}
		free(texture_id);
	}
	if (!map->texture[NO] || !map->texture[SO] || !map->texture[WE]
		|| !map->texture[EA] || !scene_color_verification(map))
		return (write_error_msg(SCENE_LOAD_FAILURE));
	return (SUCCESS);
}
