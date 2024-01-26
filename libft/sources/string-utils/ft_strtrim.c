/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:07:51 by m.abdelmage       #+#    #+#             */
/*   Updated: 2022/10/09 12:38:26 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_element(char const *string, char element)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (element == string[index])
			return (1);
		index++;
	}
	return (0);
}

static char	*ft_slice(char *string, size_t start, size_t end)
{
	char	*result;
	size_t	result_index;
	size_t	index;

	if (end == 0 || string[start] == '\0')
		return (ft_calloc(1, sizeof(char)));
	result = malloc(end - start + 2);
	if (result == NULL)
		return (NULL);
	result_index = 0;
	index = start;
	while (index <= end)
	{
		result[result_index] = string[index];
		result_index++;
		index++;
	}
	result[result_index] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	if (set[0] == '\0' && s1[0] == '\0')
	{
		return (ft_calloc(1, sizeof(char)));
	}
	else if (set[0] == '\0')
	{
		return (ft_strdup((char *)s1));
	}
	start = 0;
	while (has_element(set, s1[start]))
		start++;
	end = (size_t)ft_strlen(s1) - 1;
	while (has_element(set, s1[end]) && end != 0)
		end--;
	return (ft_slice((char *)s1, start, end));
}
