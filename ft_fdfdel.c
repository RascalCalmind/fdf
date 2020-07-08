/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fdfdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 12:05:00 by pholster       #+#    #+#                */
/*   Updated: 2019/04/05 13:33:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdfdel(t_fdf **fdf)
{
	ft_lstdel(&(*fdf)->map, &ft_lsstdelpos);
	if ((*fdf)->mlx != NULL && (*fdf)->window != NULL)
		mlx_destroy_window((*fdf)->mlx, (*fdf)->window);
	if ((*fdf)->mlx != NULL && (*fdf)->image != NULL)
		mlx_destroy_image((*fdf)->mlx, (*fdf)->image);
	if ((*fdf)->mlx != NULL)
		ft_memdel(&(*fdf)->mlx);
	ft_memdel((void **)fdf);
}
