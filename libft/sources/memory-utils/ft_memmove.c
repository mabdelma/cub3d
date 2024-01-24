/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.abdelmaged <m.abdelmaged@student.42ab    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:01:49 by m.abdelmage       #+#    #+#             */
/*   Updated: 2022/10/07 08:01:52 by m.abdelmage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	size_t	i;

	if (n == 0)
		return (d);
	if ((uintptr_t)s < (uintptr_t)d)
	{
		i = n - 1;
		while (i > 0)
		{
			((unsigned char *)d)[i] = ((unsigned const char *)s)[i];
			i--;
		}
		((unsigned char *)d)[i] = ((unsigned const char *)s)[i];
	}
	else if ((uintptr_t)d < (uintptr_t)s)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)d)[i] = ((unsigned const char *)s)[i];
			i++;
		}
	}
	return (d);
}
