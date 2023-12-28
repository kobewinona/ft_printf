/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:19:39 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/15 19:19:40 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

int	print_with_width(t_print_func print_func, t_fdata *fdata)
{
	if (fdata->justify == 1 && fdata->width)
	{
		if (print_width(fdata) < 0)
			return (-1);
	}
	if (print_func(fdata) < 0)
		return (-1);
	if (fdata->justify == -1 && fdata->width)
	{
		if (print_width(fdata) < 0)
			return (-1);
	}
	if (fdata->width > fdata->len)
		fdata->len += (fdata->width - fdata->len);
	return (1);
}
