/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fdfnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 12:59:56 by pholster       #+#    #+#                */
/*   Updated: 2019/04/10 17:07:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*freeret(char *str, t_fdf **fdf, char ***arr, char **filestr)
{
	ft_puterror(str);
	ft_strarrdel(arr);
	ft_strdel(filestr);
	ft_fdfdel(fdf);
	return (NULL);
}

t_fdf			*ft_fdfnew(int fd)
{
	t_fdf	*fdf;
	char	*str;
	char	**arr;

	fdf = ft_fdfsetdefualt();
	if (fdf == NULL)
		return (freeret(ERROR_ALLOCATION, NULL, NULL, NULL));
	str = ft_readfile(fd);
	ft_strreplace(&str, ft_strtrim(str));
	if (str == NULL)
		return (freeret(ERROR_ALLOCATION, &fdf, NULL, NULL));
	if (ft_checkformat(str) == FALSE || ft_checklength(str, &FDF_X) == FALSE)
		return (freeret(ERROR_INVALID, &fdf, NULL, &str));
	arr = ft_strdsplit(str, " \n");
	ft_strdel(&str);
	if (arr == NULL)
		return (freeret(ERROR_ALLOCATION, &fdf, NULL, NULL));
	if (ft_addtomap(&FDF_MAP, arr, FDF_X, &FDF_Y) == FALSE)
		return (freeret(ERROR_ALLOCATION, &fdf, &arr, NULL));
	ft_strarrdel(&arr);
	return (fdf);
}
