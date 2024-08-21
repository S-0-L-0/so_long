/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:58:07 by edforte           #+#    #+#             */
/*   Updated: 2024/08/12 17:59:49 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_mkword(char const *str, int start, int end)
{
	int		i;
	char	*substr;

	i = 0;
	substr = (char *)malloc(((end - start) + 2) * sizeof(char));
	while (start <= end)
	{
		substr[i] = str[start];
		i ++;
		start ++;
	}
	substr[i] = '\0';
	return (substr);
}

static int	wds_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i])
			count ++;
		while (s[i] && s[i] != c)
			i ++;
	}
	return (count);
}

static char	**memall(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc((1 + wds_count(s, c)) * sizeof(char *));
	if (!words)
		return (NULL);
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**words;
	int		count;

	words = memall(s, c);
	if (!words)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i ++;
			words[count++] = ft_mkword(s, start, (i - 1));
		}
	}
	words[count] = NULL;
	return (words);
}
