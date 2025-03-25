/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:59:16 by mhummel           #+#    #+#             */
/*   Updated: 2024/04/29 10:53:55 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_printf(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_fd_printf("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar_fd_printf('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr_fd_printf(n / 10, fd);
	}
	count += ft_putchar_fd_printf(n % 10 + '0', fd);
	return (count);
}
