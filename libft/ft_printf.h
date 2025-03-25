/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:17:25 by mhummel           #+#    #+#             */
/*   Updated: 2024/04/29 10:52:42 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr_fd_printf(char *s, int fd);
int		ft_putnbr_fd_printf(int n, int fd);
int		ft_putchar_fd_printf(char c, int fd);
int		ft_putnbr_base_p_printf(unsigned long nbr, char *base);
int		ft_putnbr_base_u_printf(unsigned int nbr, char *base);
int		ft_putnbr_base_x_printf(unsigned int nbr, char *base);
size_t	ft_strlen_printf(const char *s);
int		ft_error_printf(int status, int intial);

#endif
