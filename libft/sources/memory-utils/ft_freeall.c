/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:00:05 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:00:05 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freeall(void **double_ptr)
{
	int	i;

	if (!double_ptr || !(*double_ptr))
	{
		if (double_ptr)
			free(double_ptr);
		return ;
	}
	i = 0;
	while (double_ptr[i])
	{
		free(double_ptr[i]);
		i++;
	}
	free(double_ptr);
}
