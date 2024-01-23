/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:58:36 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/21 19:58:37 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf_internal.h"

int	print_precision(ssize_t len, t_fdata *fdata)
{
	while (len < fdata->precision)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	return (1);
}
