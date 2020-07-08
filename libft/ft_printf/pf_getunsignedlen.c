/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getunsignedlen.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 12:27:39 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_getunsignedlen(t_info *info)
{
	t_uintmax	num;

	num = pf_overflowunsigned(info);
	PF_VAR_LEN = ft_unumlen_base(num, PF_VAR_BASE);
}
