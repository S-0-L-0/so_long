/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:55:35 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 19:11:46 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_pos(t_position *player, t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->matrix[y])
	{
		while (game->matrix[y][x])
		{
			if (game->matrix[y][x] == 'P')
			{
				player->px = x;
				player->py = y;
			}
			if (game->matrix[y][x] == 'E')
			{
				player->ex = x;
				player->ey = y;
			}
			x ++;
		}
		x = 0;
		y ++;
	}
}

void	set_texture(t_texture *sprt, t_data *gm)
{
	part_one(sprt, gm);
	part_two(sprt, gm);
	return ;
}

void	collect_counter(t_data *game)
{
	int	rows;
	int	columns;

	rows = 0;
	columns = 0;
	game->collect_counter = 0;
	while (game->matrix[rows])
	{
		while (game->matrix[rows][columns])
		{
			if (game->matrix[rows][columns] == 'C')
			{
				game->collect_counter ++;
			}
			columns ++;
		}
		columns = 0;
		rows ++;
	}
}
