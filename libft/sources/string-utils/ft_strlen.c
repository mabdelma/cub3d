/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:17:19 by mabdelma          #+#    #+#             */
/*   Updated: 2022/10/09 10:28:48 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str)
{
	size_t				x;
	char				*z;

	x = 0;
	z = (char *)str + x;
	if (*z == '\0')
	{
		return (0);
	}
	while (*z != '\0')
	{
		z = (char *)str + x;
		x++;
	}
	x -= 1;
	return (x);
}
