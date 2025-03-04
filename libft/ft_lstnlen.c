/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:51:09 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 13:30:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstnlen(t_list *lst, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n && lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
