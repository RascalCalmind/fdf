/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checklength.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 12:59:56 by pholster       #+#    #+#                */
/*   Updated: 2019/04/04 20:49:19 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_checklength(char *str, int *fdfx)
{
	int		count;
	int		len;
	size_t	i;

	count = 0;
	i = 0;
	len = -1;
	while (count != -2)
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			len = *fdfx - 1;
			if (len == -1)
				*fdfx = count + 1;
			else if (count != len)
				return (FALSE);
			if (str[i] == '\0')
				return (len > 0);
			count = 0;
		}
		else if (i > 0 && str[i - 1] == ' ' && str[i] != ' ')
			count++;
		i++;
	}
	return (FALSE);
}
