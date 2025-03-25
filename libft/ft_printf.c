/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:02:53 by mhummel           #+#    #+#             */
/*   Updated: 2024/04/29 10:54:48 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formater_printf(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd_printf(va_arg(args, int), 1);
	else if (c == 's')
		count += ft_putstr_fd_printf(va_arg(args, char *), 1);
	else if (c == 'd')
		count += ft_putnbr_fd_printf(va_arg(args, int), 1);
	else if (c == '%')
		count += ft_putchar_fd_printf('%', 1);
	else if (c == 'i')
		count += ft_putnbr_fd_printf(va_arg(args, int), 1);
	else if (c == 'u')
		count += ft_putnbr_base_u_printf(va_arg(args, int), "0123456789");
	else if (c == 'x')
		count += ft_putnbr_base_x_printf(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base_x_printf(va_arg(args, int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		count += ft_putstr_fd_printf("0x", 1) + ft_putnbr_base_p_printf(\
			va_arg(args, unsigned long), "0123456789abcdef");
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	ft_error_printf(0, 1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_formater_printf(format[i], args);
		}
		else
			count += ft_putchar_fd_printf(format[i], 1);
		if (ft_error_printf(0, 0) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}
