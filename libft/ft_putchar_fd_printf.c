/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:38:43 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/02 09:55:25 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_printf(char c, int fd)
{
	if (ft_error_printf(0, 0) == 0)
		ft_error_printf(write(fd, &c, 1), 0);
	return (1);
}
