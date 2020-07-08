/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zoomset.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 20:36:04 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/10 15:38:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoomset(t_fdf *fdf, double zoom)
{
	if (zoom > MAX_ZOOM)
		FDF_CAM_ZOOM = MAX_ZOOM;
	else if (zoom < MIN_ZOOM)
		FDF_CAM_ZOOM = MIN_ZOOM;
	else
		FDF_CAM_ZOOM = zoom;
}
