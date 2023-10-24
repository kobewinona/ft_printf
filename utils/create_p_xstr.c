/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_p_xstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:21:19 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/26 12:21:20 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*create_p_xstr(void *content, ssize_t len)
{
	char	*x_s;
	size_t	n;
	long	n_mod;

	x_s = (char *)ft_calloc((len + 1), sizeof(char));
	if (!x_s)
		return (NULL);
	n = (size_t)content;
	x_s[0] = '0';
	x_s[1] = 'x';
	if (n < 0)
		n *= -1;
	while (--len > 1)
	{
		n_mod = n % 16;
		if (n_mod < 10)
			x_s[len] = n_mod + '0';
		else
			x_s[len] = (n_mod - 10) + 'a';
		n /= 16;
	}
	return (x_s);
}
