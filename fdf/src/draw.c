/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:43:53 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:00:32 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(int x, int y, t_win *win, int color)
{
	int	i;

	if (win->help == 1)
	{
		if ((x >= 230 && x < WIDTH && y >= 0 && y < HEIGHT) ||
				(x >= 0 && y > 385 && y < HEIGHT && x < WIDTH))
		{
			i = (x * win->bpp / 8) + (y * win->stride);
			win->img_data[i] = color;
			win->img_data[++i] = color >> 8;
			win->img_data[++i] = color >> 16;
		}
	}
	if (win->help == 0)
	{
		if ((x >= 165 && x < WIDTH && y >= 0 && y < HEIGHT) ||
				(x >= 0 && y > 45 && y < HEIGHT && x < WIDTH))
		{
			i = (x * win->bpp / 8) + (y * win->stride);
			win->img_data[i] = color;
			win->img_data[++i] = color >> 8;
			win->img_data[++i] = color >> 16;
		}
	}
}

void	back(t_win *win)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			{
				i = (x * win->bpp / 8) + (y * win->stride);
				win->img_data[i] = (char)win->map->back_color;
				win->img_data[++i] = (char)win->map->back_color;
				win->img_data[++i] = (char)win->map->back_color;
			}
			x++;
		}
		y++;
	}
}

void	put_pixel_last(t_xyz f, t_xyz s, t_win *win)
{
	int		i;
	int		color;
	t_xyz	delta;
	t_xyz	cur;

	delta.x = abs(s.x - f.x);
	delta.y = -abs(s.y - f.y);
	cur = f;
	color = get_color(cur, f, s, delta);
	if (win->help == 1)
	{
		if ((f.x >= 230 && f.x < WIDTH && f.y >= 0 && f.y < HEIGHT) ||
				(f.x >= 0 && f.y > 385 && f.y < HEIGHT && f.x < WIDTH))
		{
			i = (s.x * win->bpp / 8) + (s.y * win->stride);
			win->img_data[i] = color;
			win->img_data[++i] = color >> 8;
			win->img_data[++i] = color >> 16;
		}
	}
	if (win->help == 0)
	{
		put_pixel_last2(f, s, win);
	}
}

void	line(t_xyz f, t_xyz s, t_win *win)
{
	t_xyz	delta;
	t_xyz	cur;
	int		error[2];

	delta.x = abs(s.x - f.x);
	delta.y = -abs(s.y - f.y);
	error[0] = delta.x + delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		put_pixel(cur.x, cur.y, win, get_color(cur, f, s, delta));
		error[1] = error[0] * 2;
		if (error[1] > delta.y)
		{
			error[0] += delta.y;
			cur.x += f.x < s.x ? 1 : -1;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += f.y < s.y ? 1 : -1;
		}
	}
}

void	draw(t_win *win, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	back(win);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				line(view(xyz(x, y, map), win, map),
						view(xyz(x + 1, y, map), win, map), win);
			if (y != map->height - 1)
				line(view(xyz(x, y, map), win, map),
						view(xyz(x, y + 1, map), win, map), win);
			x++;
		}
		y++;
	}
	last_pixel(x, y, win, map);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img, 1, 0);
	menu(win);
}
