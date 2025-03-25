/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:45:24 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/12 12:19:20 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*ptr;

	total_size = count * size;
	i = 0;
	if (count != 0 && total_size / count != size)
	{
		return (NULL);
	}
	ptr = malloc(total_size);
	if (ptr == 0)
	{
		return (NULL);
	}
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

// int	main(void)
// {
// 	int		*arr;
// 	size_t	n;
// 	size_t	i;

// 	n = 5;
// 	i = 0;
// 	arr = (int *)ft_calloc(n, sizeof(int));
// 	if (arr == NULL)
// 	{
// 		printf("Failed.\n");
// 		return (1);
// 	}
// 	printf("The value of the arrays:\n");
// 	while (i < n)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(arr);
// 	return (0);
// }
