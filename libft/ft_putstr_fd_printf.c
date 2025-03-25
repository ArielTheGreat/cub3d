/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:43:51 by mhummel           #+#    #+#             */
/*   Updated: 2024/04/29 10:54:12 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_printf(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		if (write(fd, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchar_fd_printf(s[i], fd);
		i++;
	}
	return (i);
}
