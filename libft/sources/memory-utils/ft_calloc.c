/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:39:00 by mabdelma          #+#    #+#             */
/*   Updated: 2022/09/29 12:39:00 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (size == 0)
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = '\0';
		return (s);
	}
	if (size >= SIZE_MAX || count >= SIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
