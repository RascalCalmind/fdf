/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_imagepixelput.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 18:11:36 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 11:42:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_imagepixelput(t_fdf *fdf, int x, int y, int color)
{
	char *mem;

	mem = (char *)FDF_IMAGE_MEM;
	if (ft_inbounds(fdf, x, y) && mem[((FDF_WINDOW_X * y) + x) * 4] == 0)
		ft_memcpy(&mem[((FDF_WINDOW_X * y) + x) * 4], &color, 4);
}
