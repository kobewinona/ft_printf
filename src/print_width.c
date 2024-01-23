/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:42:57 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/24 14:42:58 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf_internal.h"

int	print_width(t_fdata *fdata)
{
	ssize_t	width;

	width = fdata->width;
	while (width > fdata->len)
	{
		if (write(1, &fdata->pad, 1) < 0)
			return (-1);
		width--;
	}
	return (1);
}
