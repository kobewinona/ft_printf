/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:06:13 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/15 20:06:14 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

static int	print_s(t_fdata *fdata)
{
	char	*s;
	ssize_t	i;

	s = NULL;
	if (!fdata->content)
		s = (char *)"(null)";
	else
		s = (char *)fdata->content;
	i = 0;
	while (s[i] && i < fdata->len)
	{
		if (write(1, &s[i], 1) < 0)
			return (-1);
		i++;
	}
	fdata->len = i;
	return (1);
}

void	print_s_with_tags(t_fdata *fdata)
{
	if (fdata->content)
		fdata->len = ft_strlen((char *)fdata->content);
	else
		fdata->len = 6;
	if (fdata->precision >= 0 && fdata->precision <= fdata->len)
	{
		fdata->len = fdata->precision;
		fdata->pad = ' ';
	}
	if (print_with_width(print_s, fdata) < 0)
		fdata->len = -1;
}
