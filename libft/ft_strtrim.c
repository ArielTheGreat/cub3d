/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:58:13 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 14:03:35 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
		{
			return (1);
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	end = len;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}

// int main() {
//     // Beispiele für die zu trimmenden Strings und Trim-Sets
//     char const *s1 = "lorem \n ipsum \t dolor \n sit \t amet";
//     char const *set1 = " ";

// //     char const *s2 = "Hello, World!";
// //     char const *set2 = "Hdle";

// //     char const *s3 = "abcdef";
// //     char const *set3 = "ac";

// //     // Trimme die Strings
//     char *trimmed1 = ft_strtrim(s1, set1);
// //     char *trimmed2 = ft_strtrim(s2, set2);
// //     char *trimmed3 = ft_strtrim(s3, set3);

// //     // Ausgabe der Ergebnisse
//     printf("Original: '%s', Getrimmt: \n '%s'\n", s1, trimmed1);
// //     printf("Original: '%s','%s'\n", s2, trimmed2);
// //     printf("Original: '%s', Getrimmt: '%s'\n", s3, trimmed3);

// //     // Speicher freigeben
//     free(trimmed1);
// //     free(trimmed2);
// //     free(trimmed3);

//     return 0;
// }
