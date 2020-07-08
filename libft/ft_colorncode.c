/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorncode.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/04/02 12:11:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_colorncode(const char *str, size_t n)
{
	char	**ret;
	char	**colors;
	size_t	i;

	i = 0;
	if (n > 16)
		n = 16;
	colors = ft_strarrnew(16);
	if (colors == NULL)
		return (-1);
	ret = ft_strarrcpy_var(colors, 16, "black", "red", "green", "yellow", \
		"blue", "magenta", "cyan", "white", "bright black", "bright red", \
		"bright green", "bright yellow", "bright blue", "bright magenta", \
		"bright cyan", "bright white");
	while (ret != NULL && i < n)
	{
		if (ft_strequ_nocase(str, colors[i]))
		{
			ft_strarrdel(&colors);
			return ((int)i);
		}
		i++;
	}
	ft_strarrdel(&colors);
	return (-1);
}
