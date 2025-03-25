/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:43:54 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/12 12:18:09 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}

// int	main(void)
// {
// 	char	c;
// 	char	output;

// 	c = 'A';
// 	printf("Original char %c\n", c);
// 	output = ft_tolower(c);
// 	printf("Original char %c\n", output);
// }
