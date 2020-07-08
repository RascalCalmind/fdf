/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawlinexplus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 14:57:02 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/15 14:16:36 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_drawlinexplus(t_fdf *fdf, t_line line, float m, t_pos *pos)
{
	int	dx;
	int	dy;
	int	xcurrent;
	int	ystep;
	int	y;

	dx = line.x2 - line.x1;
	dy = line.y2 - line.y1;
	xcurrent = line.x1;
	ystep = (dy < 0) ? -1 : 1;
	y = line.y1;
	ft_imagepixelput(fdf, xcurrent, y, ft_color(pos->z, pos->color));
	while (xcurrent < line.x2)
	{
		m -= (ystep == -1) ? -dy : dy;
		xcurrent += 1;
		if (m < 0)
		{
			y += ystep;
			m += dx;
		}
		ft_imagepixelput(fdf, xcurrent, y, ft_color(pos->z, pos->color));
	}
}
