/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fitsonscreen.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 11:48:32 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 12:23:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fitsonscreen(t_fdf *fdf, t_line line)
{
	int		zoom;

	zoom = SPACING * FDF_CAM_ZOOM;
	if (line.x1 < 0 && line.x2 < 0 && line.y1 < 0 && line.y2 < 0)
		return (FALSE);
	if (line.x2 > FDF_WINDOW_X && line.y2 > FDF_WINDOW_Y
		&& line.x1 > FDF_WINDOW_X && line.y1 > FDF_WINDOW_Y)
		return (FALSE);
	return (TRUE);
}
