/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:18:57 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 20:22:52 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **matrix, int x, int y)
{
	if (matrix[y][x] == '1')
	{
		return ;
	}
	if (matrix[y][x] == 'P' || matrix[y][x] == '0' ||
			matrix[y][x] == 'C' || matrix[y][x] == 'E')
	{
		if (matrix[y][x] == 'E')
			matrix[y][x] = 'X';
		else
			matrix[y][x] = 'x';
		flood_fill(matrix, x, y - 1);
		flood_fill(matrix, x + 1, y);
		flood_fill(matrix, x, y + 1);
		flood_fill(matrix, x - 1, y);
	}
}

int	pathfinder(char **matrix, int x, int y)
{
	int	rows;
	int	columns;
	int	exit;
	int	collect;

	rows = 0;
	columns = 0;
	exit = 0;
	collect = 0;
	flood_fill(matrix, x, y);
	while (matrix[rows])
	{
		while (matrix[rows][columns ++])
		{
			if (matrix[rows][columns] == 'X')
				exit = 1;
			if (matrix[rows][columns] == 'C')
				collect = 1;
		}
		columns = 0;
		rows ++;
	}
	if (exit == 1 && collect == 0)
		return (0);
	return (1);
}
