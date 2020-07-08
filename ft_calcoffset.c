/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calcoffset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 17:11:21 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/11 12:33:43 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	getbiggest(t_fdf *fdf, int *width, int *height)
{
	int		biggestx;
	int		biggesty;
	int		calcx;
	int		calcy;
	t_list	*map;

	map = FDF_MAP;
	biggestx = 0;
	biggesty = 0;
	while (map != NULL)
	{
		ft_calcpostoscreen(fdf, map->content, &calcx, &calcy);
		calcx -= FDF_OFFSET_X;
		calcy -= FDF_OFFSET_Y;
		if (calcx > biggestx)
			biggestx = calcx;
		if (calcy > biggesty)
			biggesty = calcy;
		map = map->next;
	}
	*width += biggestx;
	*height += biggesty;
}

static void	*getbiggest_thread(void *param)
{
	t_fdf	*fdf;
	int		*width;
	int		*height;

	fdf = (t_fdf *)((int **)param)[0];
	width = ((int **)param)[1];
	height = ((int **)param)[2];
	getbiggest(fdf, width, height);
	return (NULL);
}

static void	getsmallest(t_fdf *fdf, int *width, int *height)
{
	int		smallestx;
	int		smallesty;
	int		calcx;
	int		calcy;
	t_list	*map;

	map = FDF_MAP;
	smallestx = 0;
	smallesty = 0;
	while (map != NULL)
	{
		ft_calcpostoscreen(fdf, map->content, &calcx, &calcy);
		calcx -= FDF_OFFSET_X;
		calcy -= FDF_OFFSET_Y;
		if (calcx < smallestx)
			smallestx = calcx;
		if (calcy < smallesty)
			smallesty = calcy;
		map = map->next;
	}
	*width += smallestx;
	*height += smallesty;
}

void		ft_calcoffset(t_fdf *fdf)
{
	pthread_t	thread;
	int			width;
	int			height;
	void		*params[3];

	width = 0;
	height = 0;
	params[0] = fdf;
	params[1] = &width;
	params[2] = &height;
	if (pthread_create(&thread, NULL, &getbiggest_thread, params) != 0)
		getbiggest(fdf, &width, &height);
	getsmallest(fdf, &width, &height);
	pthread_join(thread, NULL);
	FDF_OFFSET_X = (FDF_WINDOW_X / 2) - (width / 2);
	FDF_OFFSET_Y = (FDF_WINDOW_Y / 2) - (height / 2);
}
