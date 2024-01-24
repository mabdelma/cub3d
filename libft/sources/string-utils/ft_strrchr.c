/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:00:51 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:00:52 by mabdelma         ###   ########.fr       */
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
