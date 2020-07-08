/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 16:53:56 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/11 13:57:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <time.h>

void		ft_init(t_fdf *fdf)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &ft_zoomscale, fdf) != 0)
		ft_zoomscale(fdf);
	mlx_hook(FDF_WINDOW, 2, (1L << 2), &ft_eventkeydown, fdf);
	mlx_hook(FDF_WINDOW, 3, (1L << 3), &ft_eventkeyup, fdf);
	mlx_hook(FDF_WINDOW, 4, (1L << 4), &ft_eventmousedown, fdf);
	mlx_hook(FDF_WINDOW, 5, (1L << 5), &ft_eventmouseup, fdf);
	mlx_hook(FDF_WINDOW, 6, (1L << 6), &ft_eventmousemove, fdf);
	mlx_hook(FDF_WINDOW, 17, (1L << 17), &ft_eventclose, NULL);
	pthread_join(thread, NULL);
	ft_drawmap(fdf);
	mlx_loop(FDF_MLX);
}
