/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_precision_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:59:41 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/24 18:59:42 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	count_precision_len(int n, t_fdata *fdata)
{
	ssize_t	len;

	len = fdata->len;
	if (n < 0)
		len -= 1;
	fdata->precision_len = 0;
	if (fdata->precision > len)
		fdata->precision_len = fdata->precision - len;
}
