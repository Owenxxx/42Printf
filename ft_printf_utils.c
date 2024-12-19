/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:17:35 by ojrhaide          #+#    #+#             */
/*   Updated: 2024/12/19 11:17:36 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	all_hex(unsigned int nb, char put)
{
	char	*hex;
	int		len;

	len = 0;
	if (put == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
		len += all_hex(nb / 16, put);
	len += ft_putchar(hex[nb % 16]);
	return (len);
}

int	ft_lowhex(size_t nb)
{
	char	*hex;
	int		len;

	len = 0;
	hex = "0123456789abcdef";
	if (nb >= 16)
		len += ft_lowhex(nb / 16);
	len += ft_putchar(hex[nb % 16]);
	return (len);
}

int	ft_p(void *p)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_lowhex((size_t)p);
	return (len);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
	{
		return (-1);
	}
	return (1);
}

int	ft_putnbr(int nbr)
{
	int	r;

	r = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		r += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		r += ft_putnbr(nbr / 10);
		r += ft_putnbr(nbr % 10);
	}
	else
		r += ft_putchar(nbr + 48);
	return (r);
}
