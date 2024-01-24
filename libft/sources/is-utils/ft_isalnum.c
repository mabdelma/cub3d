/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.abdelmaged <m.abdelmaged@student.42abudh +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:10 by mabdelma          #+#    #+#             */
/*   Updated: 2022/09/30 15:09:34 by m.abdelmaged     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalnum(int x)
{
	if (ft_isalpha(x) || ft_isdigit(x))
		return (8);
	return (0);
}
