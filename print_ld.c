/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:47:16 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/20 14:47:16 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

static int	print_zero(t_fdata *fdata)
{
	if (print_precision(1, fdata) < 0)
		return (-1);
	if (write(1, "0", 1) < 0)
		return (-1);
	return (1);
}

static int	print_ld_s(char *ld_s, ssize_t len, t_fdata *fdata)
{
	if (print_precision(len, fdata) < 0)
		return (-1);
	while (--len >= 0)
	{
		if (write(1, &ld_s[len], 1) < 0)
			return (-1);
	}
	return (1);
}

int	print_ld(long n, t_fdata *fdata)
{
	char	*ld_s;
	ssize_t	len;

	if (n == 0 && fdata->precision != 0)
		return (print_zero(fdata));
	ld_s = (char *)malloc((8 + 1) * sizeof(int));
	if (!ld_s)
		return (-1);
	len = 0;
	while (n > 0)
	{
		ld_s[len++] = (n % 10) + '0';
		n /= 10;
	}
	ld_s[len] = '\0';
	if (print_ld_s(ld_s, len, fdata) < 0)
	{
		free(ld_s);
		return (-1);
	}
	free(ld_s);
	return (1);
}
