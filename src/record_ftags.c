/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_tags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:21:08 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/12 21:21:09 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf_internal.h"

static void	update_fdata_with_flags(t_fdata *fdata, const char *arg)
{
	fdata->pad = ' ';
	fdata->justify = 1;
	fdata->is_preceded_with_space = 0;
	fdata->is_sign_forced = 0;
	fdata->is_preceded_with_0x = 0;
	while (*arg && !is_char_in_set(*arg, "cspdiuxX%"))
	{
		if (*arg == '-')
		{
			fdata->justify = -1;
			fdata->pad = ' ';
		}
		if (*arg == '0' && !ft_isdigit(*(arg - 1)) && fdata->justify != -1)
			fdata->pad = '0';
		if (*arg == '+')
			fdata->is_sign_forced = 1;
		if (*arg == ' ')
			fdata->is_preceded_with_space = 1;
		if (*arg == '#')
			fdata->is_preceded_with_0x = 1;
		arg++;
	}
}

static void	update_fdata_with_width(t_fdata *fdata, const char *arg)
{
	if (ft_isdigit((int)*arg))
		fdata->width = ft_atoi(arg);
	else
		fdata->width = 0;
}

static void	update_fdata_with_precision(t_fdata *fdata, const char *arg)
{
	if (*arg == '.')
		fdata->precision = ft_atoi(arg + 1);
	else
		fdata->precision = -1;
}

size_t	record_ftags(t_fdata *fdata, const char *arg)
{
	size_t	tags_len;

	tags_len = 0;
	update_fdata_with_flags(fdata, arg);
	while (*arg && is_char_in_set(*arg, "-0+ #"))
	{
		tags_len++;
		arg++;
	}
	update_fdata_with_width(fdata, arg);
	while (*arg && ft_isdigit(*arg))
	{
		tags_len++;
		arg++;
	}
	update_fdata_with_precision(fdata, arg);
	while (*arg && (ft_isdigit(*arg) || *arg == '.'))
	{
		tags_len++;
		arg++;
	}
	return (tags_len);
}
