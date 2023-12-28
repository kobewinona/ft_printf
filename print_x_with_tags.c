/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_with_tags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:07:12 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/20 16:07:13 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

static int	print_x_s(char *x_s, t_fdata *fdata)
{
	size_t	i;

	i = 0;
	if (fdata->is_preceded_with_0x == 1)
	{
		if (fdata->pad == '0' && fdata->width > fdata->len)
			i = 2;
		if (fdata->precision > fdata->len)
			i = 2;
	}
	while (x_s && x_s[i])
	{
		if (write(1, &x_s[i], 1) < 0)
			return (-1);
		i++;
	}
	if (x_s)
		x_s = NULL;
	return (1);
}

static int	print_x(t_fdata *fdata)
{
	if (print_precision(ft_strlen(fdata->hex_string), fdata) < 0)
		return (-1);
	if (print_x_s(fdata->hex_string, fdata) < 0)
		return (-1);
	return (1);
}

static int	print_0x(t_fdata *fdata)
{
	if (fdata->pad == '0' && fdata->width > fdata->len)
	{
		if (write(1, &fdata->hex_string[0], 1) < 0)
			return (-1);
		if (write(1, &fdata->hex_string[1], 1) < 0)
			return (-1);
	}
	if (fdata->precision > fdata->len)
	{
		if (write(1, &fdata->hex_string[0], 1) < 0)
			return (-1);
		if (write(1, &fdata->hex_string[1], 1) < 0)
			return (-1);
	}
	return (1);
}

static int	print_x_with_tags2(unsigned int n, t_fdata *fdata)
{
	if (fdata->is_preceded_with_0x && n != 0)
		fdata->len += 2;
	if (n == 0)
		fdata->is_preceded_with_0x = 0;
	fdata->hex_string = create_x_xtrs(fdata->content, fdata->len, fdata->spec);
	if (!fdata->hex_string)
		return (-1);
	if (fdata->is_preceded_with_0x == 1)
	{
		fdata->hex_string[1] = fdata->spec;
		if (print_0x(fdata) < 0)
			return (-1);
	}
	if (print_with_width(print_x, fdata) < 0)
		return (-1);
	return (1);
}

void	print_x_with_tags(t_fdata *fdata)
{
	unsigned int	n;

	n = (unsigned int)fdata->content;
	fdata->len = count_hex_len(n);
	count_precision_len(0, fdata);
	if (fdata->precision_len > 0)
		fdata->len += fdata->precision_len;
	if (fdata->precision >= 0)
		fdata->pad = ' ';
	if (fdata->precision == 0 && n == 0)
		fdata->len = 0;
	if (n >= 0 && (fdata->is_sign_forced || fdata->is_preceded_with_space))
		fdata->len += 1;
	if (print_preceeding_flags(n, fdata) < 0)
	{
		fdata->len = -1;
		return ;
	}
	if (print_x_with_tags2(n, fdata) < 0)
		fdata->len = -1;
	if (fdata->hex_string)
		free(fdata->hex_string);
}
