/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:50:33 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 13:13:43 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// 	char	c;

// 	c = '4';
// 	printf("%d \n", ft_isascii(c));
// 	printf("%d \n", isascii(c));
// }
