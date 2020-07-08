/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawmap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 17:11:21 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/12 16:06:59 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawliney(t_fdf *fdf, t_list *map, t_line line, t_pos *start)
{
	int		y;

	y = ((t_pos *)(map->content))->y;
	map = ft_lstindex(map, FDF_X);
	if (map == NULL || ((t_pos *)(map->content))->y - 1 != y)
		return ;
	ft_calcpostoscreen(fdf, map->content, &line.x2, &line.y2);
	ft_drawline(fdf, line, start, map->content);
}

static void	*drawmapy(void *params)
{
	t_fdf		*fdf;
	t_line		line;
	t_list		*map;

	fdf = (t_fdf *)params;
	map = FDF_MAP;
	while (map->next != NULL)
	{
		ft_calcpostoscreen(fdf, map->content, &line.x1, &line.y1);
		drawliney(fdf, map, line, map->content);
		map = map->next;
	}
	return (NULL);
}

static void	*drawmapx(void *params)
{
	size_t		i;
	t_fdf		*fdf;
	t_line		line;
	t_list		*map;

	i = 0;
	fdf = (t_fdf *)params;
	map = FDF_MAP;
	while (map->next != NULL)
	{
		i++;
		if (i % FDF_X != 0)
		{
			ft_calcpostoscreen(fdf, map->content, &line.x1, &line.y1);
			ft_calcpostoscreen(fdf, map->next->content, &line.x2, &line.y2);
			ft_drawline(fdf, line, map->content, map->next->content);
		}
		map = map->next;
	}
	return (NULL);
}

static void	drawinfo(t_fdf *fdf)
{
	int	y;

	y = -14;
	ft_puttext(fdf, 8, y += 18, "ZOOM: SCROLL WHEEL");
	ft_puttext(fdf, 8, y += 18, "SWITCH: SPACE");
	ft_puttext(fdf, 8, y += 18, "ROTATE: LEFT MOUSE / ARROW KEYS");
	ft_puttext(fdf, 8, y += 18, "ROTATE Z: PAGE UP & PAGE DOWN");
	ft_puttext(fdf, 8, y += 18, "RESET ROTATION: R");
	if (FDF_CAM_PROJECTION == flat)
		ft_puttext(fdf, 8, y += (18 * 2), "CURRENT: FLAT");
	else if (FDF_CAM_PROJECTION == parrallel)
		ft_puttext(fdf, 8, y += (18 * 2), "CURRENT: PARRALLEL");
	else if (FDF_CAM_PROJECTION == false_iso)
		ft_puttext(fdf, 8, y += (18 * 2), "CURRENT: 2:1 ISOMETRIC");
	else
		ft_puttext(fdf, 8, y += (18 * 2), "CURRENT: TRUE ISOMETRIC");
}

void		ft_drawmap(t_fdf *fdf)
{
	pthread_t	thread;

	ft_calcoffset(fdf);
	ft_bzero(FDF_IMAGE_MEM, (FDF_WINDOW_X * FDF_WINDOW_Y) * 4);
	if (pthread_create(&thread, NULL, &drawmapy, fdf) != 0)
		drawmapy(fdf);
	drawmapx(fdf);
	mlx_clear_window(FDF_MLX, FDF_WINDOW);
	pthread_join(thread, NULL);
	mlx_put_image_to_window(FDF_MLX, FDF_WINDOW, FDF_IMAGE, 0, 0);
	drawinfo(fdf);
}
