/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lsttostrarr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:55:27 by pholster       #+#    #+#                */
/*   Updated: 2019/03/17 13:31:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeret(char **arr)
{
	free(arr);
	return (NULL);
}

char		**ft_lsttostrarr(t_list *lst)
{
	char	**arr;
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_lstlen(lst);
	if (len == 0)
		return (NULL);
	arr = ft_strarrnew(len);
	if (arr == NULL)
		return (NULL);
	while (lst != NULL)
	{
		str = ft_strdup((char *)lst->content);
		if (str == NULL)
			return (freeret(arr));
		arr[i] = str;
		lst = lst->next;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
