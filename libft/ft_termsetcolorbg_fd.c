/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolorbg_fd.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:21:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termsetcolorbg_fd(int color, int fd)
{
	if (color < 0 || color > 255)
	{
		ft_termresetcolorbg_fd(fd);
		return ;
	}
	ft_putstr_fd("\e[48;5;", fd);
	ft_putnbr_fd(color, fd);
	ft_putchar_fd('m', fd);
}
