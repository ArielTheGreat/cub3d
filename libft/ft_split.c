/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:57:30 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/20 10:26:36 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **arr)
{
	int	aindex;

	aindex = 0;
	while (arr[aindex])
		free(arr[aindex++]);
	free(arr);
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*next_word(const char *str, char c, int *j)
{
	int		start;
	int		end;
	char	*word;

	while (str[*j] && str[*j] == c)
		(*j)++;
	start = *j;
	while (str[*j] && str[*j] != c)
		(*j)++;
	end = *j;
	word = ft_substr(str, start, end - start);
	if (word == NULL)
		return (NULL);
	return (word);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		word_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	word_count = count_words(str, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < word_count)
	{
		result[i] = next_word(str, c, &j);
		if (result[i] == NULL)
		{
			ft_free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	**result;
// 	int		i;

// 	result = ft_split("Hello Stupid World", ' ');
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }
