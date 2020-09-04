/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:48:36 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:53:59 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel_last2(t_xyz f, t_xyz s, t_win *win)
{
	int		i;
	int		color;
	t_xyz	delta;
	t_xyz	cur;

	delta.x = abs(s.x - f.x);
	delta.y = -abs(s.y - f.y);
	cur = f;
	color = get_color(cur, f, s, delta);
	if ((f.x >= 165 && f.x < WIDTH && f.y >= 0 && f.y < HEIGHT) ||
			(f.x >= 0 && f.y > 45 && f.y < HEIGHT && f.x < WIDTH))
	{
		i = (s.x * win->bpp / 8) + (s.y * win->stride);
		win->img_data[i] = color;
		win->img_data[++i] = color >> 8;
		win->img_data[++i] = color >> 16;
	}
}
