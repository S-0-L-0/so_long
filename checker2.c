/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:33:31 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 20:40:48 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chrs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'E' && \
		str[i] != 'P' && str[i] != 'C' && str[i] != '\n')
			return (1);
		if (i < ft_strlen(str))
		{
			if (str[i] == '\n' && str[i + 1] == '\n')
				return (1);
		}
		i ++;
	}
	if (nbr_objects(str) == 1)
		return (1);
	return (0);
}

int	nbr_objects(char *str)
{
	int	start;
	int	exit;
	int	collectibles;
	int	i;

	start = 0;
	exit = 0;
	collectibles = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			start ++;
		else if (str[i] == 'E')
			exit ++;
		else if (str[i] == 'C')
			collectibles ++;
		i ++;
	}
	if (start != 1 || exit != 1 || collectibles < 1)
		return (1);
	return (0);
}

int	matrix_check(t_data *game)
{
	int	line_size;
	int	columns_size;

	columns_size = 0;
	line_size = ft_strlen(game->matrix[columns_size]);
	columns_size ++;
	while (game->matrix[columns_size])
	{
		if (line_size - ft_strlen(game->matrix[columns_size]) != 0)
		{
			ft_printf("%s\n", MAP_ERROR2);
			return (1);
		}
		columns_size ++;
	}
	game->max_x = line_size;
	game->max_y = columns_size;
	if (all_walls(game) == 1)
	{
		ft_printf("%s\n", MAP_ERROR3);
		return (1);
	}
	return (0);
}

int	all_walls(t_data *game)
{
	int	rows;
	int	columns;

	rows = 0;
	columns = 0;
	if (rows_check(game, rows) != 0 || \
		columns_check(game, columns != 0))
		return (1);
	return (0);
}
