/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:23:58 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/11 19:24:00 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;
	size_t	min_size;

	if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(size));
	new_ptr = (void *)malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	old_size = sizeof(ptr);
	if (old_size < size)
		min_size = old_size;
	else
		min_size = size;
	ft_memcpy(new_ptr, ptr, min_size);
	free(ptr);
	return (new_ptr);
}

