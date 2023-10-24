/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:41:52 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/08 17:41:53 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	route_fspec(t_fdata *fdata)
{
	if (fdata->spec == '%')
		print_c_with_tags(fdata);
	if (fdata->spec == 'c')
		print_c_with_tags(fdata);
	if (fdata->spec == 's')
		print_s_with_tags(fdata);
	if (fdata->spec == 'p')
		print_p_with_tags(fdata);
	if (fdata->spec == 'd' || fdata->spec == 'i')
		print_di_with_tags(fdata);
	if (fdata->spec == 'u')
		print_u_with_tags(fdata);
	if (fdata->spec == 'x' || fdata->spec == 'X')
		print_x_with_tags(fdata);
}

static size_t	print_fspec(const char *arg, va_list argv)
{
	t_fdata	*fdata;
	size_t	len;

	len = 0;
	fdata = (t_fdata *)malloc(sizeof(t_fdata));
	if (!fdata)
		return (-1);
	arg += record_ftags(fdata, arg);
	fdata->spec = *arg;
	if (fdata->spec == '%')
		fdata->content = (void *)('%');
	else
		fdata->content = va_arg(argv, void *);
	fdata->len = 0;
	route_fspec(fdata);
	len = fdata->len;
	free(fdata);
	return (len);
}

static ssize_t	handle_print(const char *arg, va_list argv)
{
	ssize_t	spec_len;
	ssize_t	total_len;

	total_len = 0;
	while (*arg)
	{
		spec_len = 0;
		if (is_valid_fdata(arg))
		{
			spec_len = print_fspec(++arg, argv);
			if (spec_len < 0)
				return (-1);
			while (!is_char_in_set(*arg, "cspdiuxX%"))
				arg++;
		}
		else
		{
			spec_len = write(1, &(*arg), 1);
			if (spec_len < 0)
				return (-1);
		}
		total_len += spec_len;
		arg++;
	}
	return (total_len);
}

int	ft_printf(const char *arg, ...)
{
	va_list	argv;
	ssize_t	total_len;

	total_len = 0;
	va_start(argv, arg);
	total_len = handle_print(arg, argv);
	if (total_len < 0)
	{
		va_end(argv);
		return (-1);
	}
	va_end(argv);
	return (total_len);
}
