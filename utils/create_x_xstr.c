/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_x_xstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:28:51 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/26 12:28:52 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf_internal.h"

char	*create_x_xtrs(void *content, ssize_t len, char spec)
{
	char	*x_s;
	long	n;
	long	n_mod;

	x_s = NULL;
	x_s = (char *)ft_calloc((len + 1), sizeof(char));
	if (!x_s)
		return (NULL);
	n = (unsigned int)content;
	x_s[len] = '\0';
	while (len-- > 0)
	{
		n_mod = n % 16;
		if (n_mod < 10)
			x_s[len] = n_mod + '0';
		else
			x_s[len] = n_mod + (spec - 33);
		n /= 16;
	}
	return (x_s);
}
