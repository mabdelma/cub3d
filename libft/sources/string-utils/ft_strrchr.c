/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:32:45 by oaydemir          #+#    #+#             */
/*   Updated: 2022/10/09 10:23:48 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t	index;

	index = (size_t)ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)(&(s[ft_strlen(s)])));
	else if (s[0] == '\0')
		return (NULL);
	while (index != 0)
	{
		if (s[index] == (char) c)
			return ((char *) &(s[index]));
		index--;
	}
	if (s[index] == (char) c)
		return ((char *) &(s[index]));
	return (NULL);
}
