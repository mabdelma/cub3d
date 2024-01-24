/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:52:28 by mabdelma          #+#    #+#             */
/*   Updated: 2022/09/29 12:52:28 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillup(char const *s, unsigned int start, size_t len, char *str)
{
	size_t	g_i;
	size_t	g_j;

	g_i = (size_t)start;
	g_j = 0;
	while (s[g_i])
	{
		if (g_j < len)
			str[g_j++] = s[g_i];
		g_i++;
	}
	str[g_j] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (len == 0 || (int)start > (int)ft_strlen(s))
		return (ft_strdup(""));
	if ((int)len <= (int)ft_strlen(s) - (int)start)
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!str)
		return (NULL);
	fillup(s, start, len, str);
	return (str);
}
