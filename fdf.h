/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 08:36:05 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/15 14:16:43 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"
# include "keycodes.h"

# include <math.h>
# include <pthread.h>

enum			e_prj
{
	parrallel,
	false_iso,
	true_iso,
	flat
};

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_line;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_pos;

typedef struct	s_camera
{
	double		x;
	double		y;
	double		z;
	double		zoom;
	enum e_prj	projection;
}				t_camera;

typedef struct	s_fdf
{
	t_list		*map;
	void		*mlx;
	void		*window;
	void		*image;
	void		*image_mem;
	int			image_bits;
	t_camera	camera;
	short		mousepos[2];
	char		helddown[6];
	int			window_x;
	int			window_y;
	int			offset[2];
	int			x;
	int			y;
}				t_fdf;

# define FDF_MAP			fdf->map
# define FDF_MLX			fdf->mlx
# define FDF_WINDOW			fdf->window
# define FDF_WINDOW_X		fdf->window_x
# define FDF_WINDOW_Y		fdf->window_y
# define FDF_IMAGE			fdf->image
# define FDF_IMAGE_MEM		fdf->image_mem
# define FDF_IMAGE_BITS		fdf->image_bits
# define FDF_OFFSET			fdf->offset
# define FDF_OFFSET_X		fdf->offset[0]
# define FDF_OFFSET_Y		fdf->offset[1]
# define FDF_CAM			fdf->camera
# define FDF_CAM_X			FDF_CAM.x
# define FDF_CAM_Y			FDF_CAM.y
# define FDF_CAM_Z			FDF_CAM.z
# define FDF_CAM_ZOOM		FDF_CAM.zoom
# define FDF_CAM_PROJECTION	FDF_CAM.projection
# define FDF_MOUSEPOS		fdf->mousepos
# define FDF_MOUSEPOS_X		FDF_MOUSEPOS[0]
# define FDF_MOUSEPOS_Y		FDF_MOUSEPOS[1]
# define FDF_HELDDOWN		fdf->helddown
# define FDF_RIGHTMOUSE		FDF_HELDDOWN[0]
# define FDF_LEFTMOUSE		FDF_HELDDOWN[1]
# define FDF_ALT			FDF_HELDDOWN[2]
# define FDF_WIN			FDF_HELDDOWN[3]
# define FDF_CTRL			FDF_HELDDOWN[4]
# define FDF_SHIFT			FDF_HELDDOWN[5]
# define FDF_X				fdf->x
# define FDF_Y				fdf->y
# define SPACING			1
# define MIN_ZOOM			1
# define MAX_ZOOM			400
# define MESSAGE_USAGE		"./fdf <file with map>\n"
# define ERROR_INVALID		"Invalid map\n"
# define ERROR_ALLOCATION	"Allocation failed\n"
# define ERROR_MLXWIDNOW	"Mlx Connection Failed\n"

void			ft_puttext(t_fdf *fdf, int x, int y, char *str);
int				ft_eventmousemove(int x, int y, t_fdf *fdf);
int				ft_eventmouseup(int mousecode, int x, int y, t_fdf *fdf);
int				ft_eventkeyup(int keycode, t_fdf *fdf);
int				ft_eventkeydown(int keycode, t_fdf *fdf);
void			ft_setcampos(double *axis, double value);
int				ft_fitsonscreen(t_fdf *fdf, t_line line);
int				ft_addtomap(t_list **map, char **arr, int fdfx, int *fdfy);
int				ft_checkformat(char *str);
int				ft_checklength(char *str, int *fdfx);
int				ft_color(int z, int color);
int				ft_eventclose(void *param);
int				ft_eventmousedown(int mousecode, int x, int y, t_fdf *fdf);
int				ft_inbounds(t_fdf *fdf, int x, int y);
int				ft_widownew(t_fdf *fdf, int x, int y);
t_fdf			*ft_fdfnew(int fd);
t_fdf			*ft_fdfsetdefualt(void);
t_pos			*ft_posnew(int x, int y, int z, char *color);
void			ft_calcpostoscreen(t_fdf *fdf, t_pos *pos, int *x, int *y);
void			ft_drawline(t_fdf *fdf, t_line line, t_pos *start, t_pos *end);
void			ft_drawlinexplus(t_fdf *fdf, t_line line, float m, t_pos *pos);
void			ft_drawlineyplus(t_fdf *fdf, t_line line, float m, t_pos *pos);
void			ft_drawmap(t_fdf *fdf);
void			ft_fdfdel(t_fdf **fdf);
void			ft_imagepixelput(t_fdf *fdf, int x, int y, int color);
void			ft_init(t_fdf *fdf);
void			ft_lsstdelpos(void *pos, size_t size);
void			*ft_zoomscale(void *param);
void			ft_zoomset(t_fdf *fdf, double zoom);
void			ft_calcoffset(t_fdf *fdf);
void			ft_calcpos(t_fdf *fdf, t_pos *pos, int *x, int *y);

#endif
