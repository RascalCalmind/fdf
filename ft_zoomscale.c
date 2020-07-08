/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zoomscale.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 12:45:20 by pholster       #+#    #+#                */
/*   Updated: 2019/04/10 17:44:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	getextreme(t_fdf *fdf, int *x, int *y)
{
	int		extremex;
	int		extremey;
	int		calcx;
	int		calcy;
	t_list	*map;

	map = FDF_MAP;
	extremex = 0;
	extremey = 0;
	while (map != NULL)
	{
		ft_calcpostoscreen(fdf, map->content, &calcx, &calcy);
		if (calcx > extremex)
			extremex = calcx;
		if (abs(calcy) > extremey)
			extremey = calcy;
		map = map->next;
	}
	*x = extremex;
	*y = extremey;
}

void		*ft_zoomscale(void *param)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	fdf = param;
	x = 0;
	y = 0;
	ft_calcoffset(fdf);
	while (FDF_CAM_ZOOM > MIN_ZOOM)
	{
		ft_zoomset(fdf, FDF_CAM_ZOOM / 1.1);
		ft_calcoffset(fdf);
		getextreme(fdf, &x, &y);
		if (x < (FDF_WINDOW_X) && x >= 0 && y < (FDF_WINDOW_Y) && y >= 0)
			break ;
	}
	return (NULL);
}
