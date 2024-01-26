/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:52:49 by mabdelma          #+#    #+#             */
/*   Updated: 2022/09/29 12:52:49 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && s1[index] != '\0' && s2[index] != '\0')
	{
		if ((unsigned char) s1[index] != (unsigned char) s2[index])
			return ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
	}
	if (index < n && (unsigned char) s1[index] != (unsigned char) s2[index])
		return ((unsigned char) s1[index] - (unsigned char) s2[index]);
	return (0);
}
