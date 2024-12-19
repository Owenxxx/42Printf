/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:29:19 by ojrhaide          #+#    #+#             */
/*   Updated: 2024/12/18 05:29:20 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb > 9)
	{
		len += ft_putunsigned(nb / 10);
		len += ft_putchar((nb % 10) + '0');
	}
	else
		len += ft_putchar(nb + '0');
	return (len);
}
