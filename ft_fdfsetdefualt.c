/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fdfsetdefualt.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 12:59:56 by pholster       #+#    #+#                */
/*   Updated: 2019/04/10 17:07:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf			*ft_fdfsetdefualt(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (NULL);
	FDF_MAP = NULL;
	FDF_MLX = NULL;
	FDF_WINDOW = NULL;
	FDF_IMAGE = 0;
	FDF_X = 0;
	FDF_Y = 0;
	FDF_WINDOW_Y = 0;
	FDF_WINDOW_X = 0;
	FDF_CAM_X = 0;
	FDF_CAM_Y = 0;
	FDF_CAM_Z = 0;
	FDF_CAM_ZOOM = MAX_ZOOM;
	FDF_OFFSET_X = 0;
	FDF_OFFSET_Y = 0;
	FDF_CAM_PROJECTION = flat;
	ft_bzero(FDF_HELDDOWN, 6);
	ft_bzero(FDF_MOUSEPOS, 2);
	return (fdf);
}
