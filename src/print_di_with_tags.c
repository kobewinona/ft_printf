/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:15:08 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/19 16:15:10 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf_internal.h"

static int	print_preceeding_signs(long n, t_fdata *fdata)
{
	if (fdata->pad != ' ')
	{
		if (n < 0)
		{
			if (write(1, "-", 1) < 0)
				return (-1);
		}
		if (print_preceeding_flags(n, fdata) < 0)
			return (-1);
	}
	return (1);
}

static int	print_di(t_fdata *fdata)
{
	long	n;

	n = (int)fdata->content;
	if (fdata->pad == ' ')
	{
		if (print_preceeding_flags(n, fdata) < 0)
		{
			fdata->len = -1;
			return (-1);
		}
	}
	if (n < 0)
	{
		if (fdata->pad == ' ')
		{
			if (write(1, "-", 1) < 0)
				return (-1);
		}
		n *= -1;
	}
	if (print_ld(n, fdata) < 0)
		return (-1);
	return (1);
}

void	print_di_with_tags(t_fdata *fdata)
{
	long	n;

	n = (int)fdata->content;
	fdata->len = count_dec_len(n);
	count_precision_len(n, fdata);
	if (fdata->precision_len > 0)
		fdata->len += fdata->precision_len;
	if (fdata->precision >= 0)
		fdata->pad = ' ';
	if (fdata->precision == 0 && n == 0)
		fdata->len = 0;
	if (n >= 0 && (fdata->is_sign_forced || fdata->is_preceded_with_space))
		fdata->len += 1;
	if (print_preceeding_signs(n, fdata) < 0)
	{
		fdata->len = -1;
		return ;
	}
	if (print_with_width(print_di, fdata) < 0)
		fdata->len = -1;
}
