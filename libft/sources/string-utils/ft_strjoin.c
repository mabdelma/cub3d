/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:00:32 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:00:33 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	src_index;
	char	*result;
	size_t	result_index;

	if (!s1 || !s2)
		return (0);
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (result == NULL)
		return (NULL);
	result_index = 0;
	src_index = 0;
	while (s1[src_index] != '\0')
		result[result_index++] = s1[src_index++];
	src_index = 0;
	while (s2[src_index] != '\0')
	{
		result[result_index] = s2[src_index];
		result_index++;
		src_index++;
	}
	result[result_index] = '\0';
	return (result);
}

char	*ft_strjoin_m(char *stash, char *buffer)
{
	char	*string;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	string = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (stash && stash[i])
	{
		string[i] = stash[i];
		i++;
	}
	free(stash);
	j = 0;
	while (buffer[j])
		string[i++] = buffer[j++];
	string[i] = '\0';
	return (string);
}
