/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:52:51 by m.abdelmage       #+#    #+#             */
/*   Updated: 2022/10/09 10:19:54 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dstlen;
	size_t	src_index;

	if (dstsize == 0)
	{
		return ((size_t)ft_strlen(src));
	}
	dstlen = (size_t)ft_strlen(dst);
	index = dstlen;
	src_index = 0;
	if (dstsize - dstlen > 1 && ft_strlen(src))
	{
		while (index < (dstsize - 1) && src[src_index] != '\0')
		{
			dst[index] = src[src_index];
			src_index++;
			index++;
		}
		if (dstlen > dstsize)
			return (dstsize + (size_t)ft_strlen(src));
		dst[index] = '\0';
	}
	return (dstlen + (size_t)ft_strlen(src));
}
