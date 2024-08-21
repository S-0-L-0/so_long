/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:23:59 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 17:41:13 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char			*strres;
	int				end;
	int				i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len >= (ft_strlen(s)))
		len = (ft_strlen(s));
	end = start + len;
	strres = (char *) malloc((len + 1) * sizeof(char));
	if (!strres)
		return (NULL);
	i = 0;
	while (start < end)
	{
		strres[i] = s[start];
		start ++;
		i ++;
	}
	strres[i] = '\0';
	return (strres);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (a[i] || b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i ++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i ++;
	}
	s2[i] = '\0';
	return (s2);
}
