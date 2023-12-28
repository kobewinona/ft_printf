/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_fdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:04:31 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/14 21:04:33 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf_internal.h"

int	is_valid_fdata(const char *arg)
{
	size_t	i;

	i = 0;
	if (arg[i] == '%' && arg[i + 1] != '\0')
	{
		while (arg[i] && !ft_isdigit(arg[i]))
		{
			if (is_char_in_set(arg[i], "cspdiuxX%"))
				return (1);
			i++;
		}
		while (arg[i])
		{
			if (is_char_in_set(arg[i], "cspdiuxX%") && !ft_isspace(arg[i]))
				return (1);
			i++;
		}
	}
	return (0);
}
