/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:00:06 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/14 13:41:56 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	fill_str(char *str, unsigned int num, int *index)
{
	if (num >= 10)
	{
		fill_str(str, num / 10, index);
	}
	str[(*index)++] = (num % 10) + '0';
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	else if (n < 0)
	{
		str[i++] = '-';
		fill_str(str, -n, &i);
	}
	else
	{
		fill_str(str, n, &i);
	}
	return (str);
}

// int	main(void)
// {
// 	int	num;

// 	num = -215;
// 	printf("str: %s\n", ft_itoa(num));
// 	return (0);
// }
