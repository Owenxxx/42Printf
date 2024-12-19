/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:28:55 by ojrhaide          #+#    #+#             */
/*   Updated: 2024/12/19 11:20:16 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char c)
{
	int	print;

	print = 0;
	if (c == 'd' || c == 'i')
		print += ft_putnbr(va_arg(args, int));
	else if (c == 'X' || c == 'x')
		print += all_hex(va_arg(args, int), c);
	else if (c == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		print += ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		print += ft_p(va_arg(args, void *));
	else if (c == '%')
		print += ft_putchar('%');
	return (print);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len += ft_check(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
