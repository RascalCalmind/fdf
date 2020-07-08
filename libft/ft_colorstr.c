/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/04/02 12:10:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_colorstr(int color)
{
	char	*str;
	char	**ret;
	char	**colors;

	if (color > 15 || color < 0)
		return (NULL);
	colors = ft_strarrnew(16);
	if (colors == NULL)
		return (NULL);
	str = NULL;
	ret = ft_strarrcpy_var(colors, 16, "black", "red", "green", "yellow", \
		"blue", "magenta", "cyan", "white", "bright black", "bright red", \
		"bright green", "bright yellow", "bright blue", "bright magenta", \
		"bright cyan", "bright white");
	if (ret != NULL)
		str = ft_strdup(colors[color]);
	ft_strarrdel(&colors);
	return (str);
}
