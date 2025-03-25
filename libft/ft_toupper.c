/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:25:39 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/12 12:18:06 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}

// int	main(void)
// {
// 	char	c;
// 	char	output;

// 	c = 'a';
// 	printf("Original char %c\n", c);
// 	output = ft_toupper(c);
// 	printf("Original char %c\n", output);
// }
