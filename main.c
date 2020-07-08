/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 12:53:26 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/10 17:07:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	freeret(char *str, int fd)
{
	ft_puterror(str);
	if (fd != -1)
		close(fd);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	argc--;
	fd = -1;
	if (argc != 1)
		return (freeret(MESSAGE_USAGE, fd));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (freeret(MESSAGE_USAGE, -1));
	fdf = ft_fdfnew(fd);
	if (fdf == NULL)
		return (freeret("", fd));
	if (ft_widownew(fdf, 1920, 1080) == FALSE)
		return (freeret("", fd));
	ft_init(fdf);
	ft_fdfdel(&fdf);
	close(fd);
}
