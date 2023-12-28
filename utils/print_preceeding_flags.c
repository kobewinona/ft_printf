/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_preceeding_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:19:19 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/24 20:19:20 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf_internal.h"

int	print_preceeding_flags(long n, t_fdata *fdata)
{
	if (fdata->is_sign_forced && n >= 0)
	{
		if (write(1, "+", 1) < 0)
			return (-1);
	}
	if (fdata->is_preceded_with_space && n >= 0)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
	}
	return (1);
}
