/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:20:37 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/15 19:20:38 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

static int	print_c(t_fdata *fdata)
{
	char	*c_p;

	c_p = (char *)fdata->content;
	return (write(1, &c_p, 1));
}

void	print_c_with_tags(t_fdata *fdata)
{
	fdata->len = 1;
	if (print_with_width(print_c, fdata) < 0)
		fdata->len = -1;
}
