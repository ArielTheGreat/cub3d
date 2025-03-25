/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_x_printf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:17:58 by mhummel           #+#    #+#             */
/*   Updated: 2024/04/29 11:20:11 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_is_valid_x(char *base)
{
	int	i;
	int	j;

	if (!base || !base[1])
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'A'
					&& base[i] <= 'Z') || (base[i] >= 'a' && base[i] <= 'z')))
		{
			return (0);
		}
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base_aux_x(unsigned int nbr, char *base, int base_len,
		int *count)
{
	if (nbr < (unsigned int)base_len)
	{
		*count += ft_putchar_fd_printf(base[nbr], 1);
	}
	else
	{
		ft_putnbr_base_aux_x(nbr / base_len, base, base_len, count);
		ft_putnbr_base_aux_x(nbr % base_len, base, base_len, count);
	}
}

int	ft_putnbr_base_x_printf(unsigned int nbr, char *base)
{
	int	base_len;
	int	count;

	count = 0;
	base_len = base_is_valid_x(base);
	if (base_len > 1)
	{
		ft_putnbr_base_aux_x(nbr, base, base_len, &count);
	}
	return (count);
}
