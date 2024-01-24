/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.abdelmaged <m.abdelmaged@student.42abudh +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:36:05 by m.abdelmaged      #+#    #+#             */
/*   Updated: 2022/09/30 15:36:05 by m.abdelmaged     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n--)
		if (*s++ == (unsigned char)c)
			return (s - 1);
	return (NULL);
}
