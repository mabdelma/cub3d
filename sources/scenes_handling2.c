/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_handling2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:29 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:02:30 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*texture_id_getting(char *current_map_row)
{
	int	id_length;

	id_length = 0;
	while (current_map_row[id_length] && current_map_row[id_length] != ' ')
		id_length++;
	if (id_length != 2 && id_length != 1)
		return (FAILURE);
	return (ft_substr(current_map_row, 0, id_length));
}

int	scene_color_verification(t_map *map)
{
	int	i;

	i = 0;
	while (i < TOTAL_COLORS)
	{
		if (map->f_color[i++] == NOT_SET)
			return (FAILURE);
	}
	i = 0;
	while (i < TOTAL_COLORS)
	{
		if (map->c_color[i++] == NOT_SET)
			return (FAILURE);
	}
	return (SUCCESS);
}

bool	empty_row_checking(char *current_map_row)
{
	while (current_map_row && *current_map_row)
	{
		if (!ft_iswhitespace(*current_map_row) && *current_map_row != '\n')
			break ;
		else
			current_map_row++;
	}
	if (current_map_row && *current_map_row)
		return (false);
	return (true);
}

int	scene_color_validation(char *color_string)
{
	size_t	i;
	size_t	comma_counter;

	i = 0;
	comma_counter = 0;
	if (!color_string || !*color_string)
		return (FAILURE);
	while (color_string[i])
	{
		if (color_string[i] == ',')
			comma_counter++;
		if (!ft_isdigit(color_string[i]) && color_string[i] != ',')
			return (FAILURE);
		i++;
	}
	if (comma_counter != 2)
		return (FAILURE);
	return (SUCCESS);
}

char	*next_row_validation(int map_fd)
{
	char	*current_map_row;

	current_map_row = ft_calloc(1, sizeof(char *));
	while (current_map_row && empty_row_checking(current_map_row))
	{
		free(current_map_row);
		current_map_row = get_next_line(map_fd);
	}
	if (current_map_row && ft_isalpha(current_map_row[0]))
		current_map_row[ft_strlen(current_map_row) - 1] = '\0';
	return (current_map_row);
}
