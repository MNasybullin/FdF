/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:18:20 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/27 16:15:56 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu(t_win *win)
{
	t_win	*mlx;
	t_win	*wind;

	mlx = win->mlx_ptr;
	wind = win->win_ptr;
	if (win->help == 1)
	{
		menu1(win);
	}
	if (win->help == 0)
	{
		mlx_string_put(mlx, wind, 1, 1, 0xb822e6, "F1 -> Help menu");
		mlx_string_put(mlx, wind, 1, 20, 0xb822e6, "ESC -> Exit");
	}
}

void	menu1(t_win *win)
{
	t_win	*mlx;
	t_win	*wind;

	mlx = win->mlx_ptr;
	wind = win->win_ptr;
	mlx_string_put(mlx, wind, 50, 1, 0x00FF00, "FdF project");
	mlx_string_put(mlx, wind, 1, 20, 0xFFD700, "Zoom:");
	mlx_string_put(mlx, wind, 20, 40, 0x228ee6, "+ | - | Scroll mouse");
	mlx_string_put(mlx, wind, 1, 60, 0xFFD700, "Move:");
	mlx_string_put(mlx, wind, 20, 80, 0x228ee6, "<- | -> ...");
	mlx_string_put(mlx, wind, 1, 100, 0xFFD700, "Rotate:");
	mlx_string_put(mlx, wind, 20, 120, 0x228ee6, "Use NumPad 4 - 9");
	mlx_string_put(mlx, wind, 1, 140, 0xFFD700, "Change projection:");
	mlx_string_put(mlx, wind, 20, 160, 0x228ee6, "I - ISO");
	mlx_string_put(mlx, wind, 20, 180, 0x228ee6, "P - PARALLEL");
	mlx_string_put(mlx, wind, 1, 200, 0xFFD700, "Change Z coordinate:");
	mlx_string_put(mlx, wind, 20, 220, 0x228ee6, "Up - A");
	mlx_string_put(mlx, wind, 20, 240, 0x228ee6, "Down - Z");
	mlx_string_put(mlx, wind, 1, 260, 0xFFD700, "Change background:");
	mlx_string_put(mlx, wind, 20, 280, 0x228ee6, "V | B | N");
	mlx_string_put(mlx, wind, 1, 300, 0xFFD700, "Change color scheme:");
	mlx_string_put(mlx, wind, 20, 320, 0x228ee6, "C");
	mlx_string_put(mlx, wind, 1, 340, 0xFFD700, "Mouse control:");
	mlx_string_put(mlx, wind, 20, 360, 0x228ee6, "Press L || R buttom");
}
