/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:09 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 13:15:51 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
// 	printf("%d \n", ft_isdigit(c));
// 	printf("%d \n", isdigit(c));
// }
