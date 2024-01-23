/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_with_tags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:00:56 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/20 13:00:57 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf_internal.h"

static int	print_u(t_fdata *fdata)
{
	unsigned int	n;

	n = (unsigned int)fdata->content;
	if (fdata->pad == ' ')
	{
		if (print_preceeding_flags(n, fdata) < 0)
			return (-1);
	}
	return (print_ld(n, fdata));
}

void	print_u_with_tags(t_fdata *fdata)
{
	unsigned int	n;

	n = (unsigned int)fdata->content;
	fdata->len = count_dec_len(n);
	count_precision_len(0, fdata);
	if (fdata->precision_len > 0)
		fdata->len += fdata->precision_len;
	if (fdata->precision >= 0)
		fdata->pad = ' ';
	if (fdata->precision == 0 && n == 0)
		fdata->len = 0;
	if (n >= 0 && (fdata->is_sign_forced || fdata->is_preceded_with_space))
		fdata->len += 1;
	if (fdata->pad != ' ')
	{
		if (print_preceeding_flags(n, fdata) < 0)
		{
			fdata->len = -1;
			return ;
		}
	}
	if (print_with_width(print_u, fdata) < 0)
		fdata->len = -1;
}
