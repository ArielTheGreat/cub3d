/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:21:44 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 13:05:35 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	tot_len;
	char	*comb_str;

	i = 0;
	j = 0;
	tot_len = (ft_strlen(s1) + ft_strlen(s2));
	comb_str = malloc(tot_len + 1);
	if (comb_str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		comb_str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		comb_str[i + j] = s2[j];
		j++;
	}
	comb_str[tot_len] = '\0';
	return (comb_str);
}

// int	main(void)
// {
// 	char const	*s1;
// 	char const	*s2;
// 	char		*result;

// 	s1 = "Hello, ";
// 	s2 = "world!";
// 	result = ft_strjoin(s1, s2);
// 	if (result == NULL)
// 	{
// 		printf("Speicherzuweisung fehlgeschlagen.\n");
// 		return (1);
// 	}
// 	printf("Ergebnis der Konkatenation: %s\n", result);
// 	// Gib den allozierten Speicher wieder frei
// 	free(result);
// 	return (0);
// }
