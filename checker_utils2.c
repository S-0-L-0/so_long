/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:08:14 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 17:43:39 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strres;
	int		i;
	int		j;
	int		len_max;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len_max = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	strres = (char *) malloc(len_max * sizeof(char));
	if (!strres)
		return (NULL);
	while (s1[i])
	{
		strres[i] = s1[i];
		i ++;
	}
	while (s2[j])
		strres[i++] = s2[j++];
	strres[i] = '\0';
	free((char *)s1);
	return (strres);
}

int	rows_check(t_data *game, int rows)
{
	while (rows < game->max_x)
	{
		if (game->matrix[0][rows] != '1')
			return (1);
		rows ++;
	}
	rows = 0;
	while (rows < game->max_x)
	{
		if (game->matrix[game->max_y - 1][rows] != '1')
			return (1);
		rows ++;
	}
	return (0);
}

int	columns_check(t_data *game, int columns)
{
	while (columns < game->max_y)
	{
		if (game->matrix[columns][0] != '1')
			return (1);
		columns ++;
	}
	columns = 0;
	while (columns < game->max_y)
	{
		if (game->matrix[columns][game->max_x - 1] != '1')
			return (1);
		columns ++;
	}
	return (0);
}
