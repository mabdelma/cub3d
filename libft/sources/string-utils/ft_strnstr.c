/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:52:05 by mabdelma          #+#    #+#             */
/*   Updated: 2022/09/29 12:52:05 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == to_find[0])
		{
			while (to_find[j] != '\0' && str[i + j] == to_find[j] && i + j < n)
			{
				if (to_find[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
