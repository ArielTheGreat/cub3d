/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:52:37 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 13:14:51 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
// 	printf("%d \n", ft_isprint(c));
// 	printf("%d \n", isprint(c));
// }
