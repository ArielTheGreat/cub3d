/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:17:49 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/15 13:48:34 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str = "Hello bigass world!";
// 	char		searched;
// 	char		*found;

// 	searched = 'l';
// 	found = ft_strrchr(str, searched);
// 	printf("The char '%c' was found and the rest of the string is: '%s'\n",
// 		searched, found);

// 	char		*found1;

// 	found1 = strrchr(str, searched);
// 	printf("The char '%c' was found and the rest of the string is: '%s'\n",
// 		searched, found1);
// }
