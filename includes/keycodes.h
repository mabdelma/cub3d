/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:20:19 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:20:19 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# if __APPLE__
#  define KEYCODE_ESC 53
#  define KEYCODE_W 13
#  define KEYCODE_A 0
#  define KEYCODE_S 1
#  define KEYCODE_D 2
#  define KEYCODE_L_ARROW 123
#  define KEYCODE_R_ARROW 124

# elif __LINUX__
#  define KEYCODE_ESC 0xFF1B
#  define KEYCODE_W 119
#  define KEYCODE_A 97
#  define KEYCODE_S 115
#  define KEYCODE_D 100
#  define KEYCODE_L_ARROW 65361
#  define KEYCODE_R_ARROW 65363

# endif

#endif