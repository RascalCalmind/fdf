/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_windownew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 16:55:46 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/10 17:05:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	freeret(char *str, t_fdf **fdf)
{
	ft_puterror(str);
	ft_fdfdel(fdf);
	return (FALSE);
}

int			ft_widownew(t_fdf *fdf, int x, int y)
{
	int	temp;

	FDF_MLX = mlx_init();
	if (FDF_MLX == NULL)
		return (freeret(ERROR_MLXWIDNOW, &fdf));
	FDF_WINDOW = mlx_new_window(FDF_MLX, x, y, "Fdf");
	if (FDF_WINDOW == NULL)
		return (freeret(ERROR_MLXWIDNOW, &fdf));
	FDF_IMAGE = mlx_new_image(FDF_MLX, x, y);
	if (FDF_WINDOW == NULL)
		return (freeret(ERROR_MLXWIDNOW, &fdf));
	FDF_IMAGE_MEM = mlx_get_data_addr(FDF_IMAGE, &FDF_IMAGE_BITS, &temp, &temp);
	FDF_WINDOW_X = x;
	FDF_WINDOW_Y = y;
	(void)temp;
	return (TRUE);
}
