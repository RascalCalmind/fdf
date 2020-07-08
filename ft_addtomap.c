/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addtomap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 14:14:47 by pholster       #+#    #+#                */
/*   Updated: 2019/04/15 14:29:18 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	freeret(t_pos **pos, t_list **lst)
{
	ft_memdel((void **)lst);
	ft_memdel((void **)pos);
	return (FALSE);
}

static char	*comma(char *str)
{
	int		y;

	y = 0;
	while (str[y] != ',' && str[y] != '\0')
		y++;
	if (str[y] == '\0')
		return (NULL);
	if (str[y] == ',')
		y++;
	return (&str[y + 2]);
}

int			ft_addtomap(t_list **map, char **arr, int fdfx, int *fdfy)
{
	int		x;
	t_pos	*pos;
	t_list	*lst;
	t_list	*prvlst;

	x = 0;
	*fdfy = 0;
	prvlst = *map;
	while (arr[x] != '\0')
	{
		if (x != 0 && (x % fdfx) == 0)
			*fdfy = *fdfy + 1;
		pos = ft_posnew((x % fdfx), *fdfy, ft_atoi(arr[x]), comma(arr[x]));
		if (pos == NULL)
			return (freeret(&pos, NULL));
		lst = ft_lstnew(0, 0);
		if (lst == NULL)
			return (freeret(&pos, &lst));
		lst->content = pos;
		(*map == NULL) ? *map = lst : ft_lstaddbck(prvlst, lst);
		prvlst = lst;
		x++;
	}
	*fdfy = *fdfy + 1;
	return (TRUE);
}
