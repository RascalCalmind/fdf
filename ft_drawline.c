/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 14:39:00 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/12 16:08:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_drawline(t_fdf *fdf, t_line line, t_pos *start, t_pos *end)
{
	int		mode;
	float	m;
	int		dx;
	int		dy;

	dx = line.x2 - line.x1;
	dy = line.y2 - line.y1;
	if (abs(dx) > abs(dy))
		mode = 1;
	else
		mode = 2;
	m = ((mode == 1) ? dx : dy) / 2;
	if (m < 0)
	{
		ft_swap(&line.x1, &line.x2);
		ft_swap(&line.y1, &line.y2);
		ft_drawline(fdf, line, end, start);
		return ;
	}
	if (ft_fitsonscreen(fdf, line) == FALSE)
		return ;
	if (mode == 1)
		ft_drawlinexplus(fdf, line, m, start);
	else if (mode == 2)
		ft_drawlineyplus(fdf, line, m, start);
}
