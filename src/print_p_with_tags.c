/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_with_tags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:49:15 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/20 19:49:16 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf_internal.h"

static int	print_x(t_fdata *fdata)
{
	char	*x_s;
	size_t	i;

	x_s = create_p_xstr(fdata->content, fdata->len);
	if (!x_s)
		return (-1);
	i = 0;
	while (x_s[i])
	{
		if (write(1, &x_s[i], 1) < 0)
		{
			free(x_s);
			return (-1);
		}
		i++;
	}
	free(x_s);
	return (1);
}

void	print_p_with_tags(t_fdata *fdata)
{
	fdata->len = 2 + count_hex_len((unsigned long)fdata->content);
	if (print_with_width(print_x, fdata) < 0)
		fdata->len = -1;
}
