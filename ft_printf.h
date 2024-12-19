/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:29:03 by ojrhaide          #+#    #+#             */
/*   Updated: 2024/12/19 11:18:32 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	all_hex(unsigned int nb, char put);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_printf(const char *counst, ...);
int	ft_p(void *p);
int	ft_putunsigned(unsigned int n);
int	ft_putnbr(int nbr);

#endif
